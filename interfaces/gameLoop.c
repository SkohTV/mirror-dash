#include "gameLoop.h"
#include "../primitives/core.h"
#include "../primitives/fileCreator.h"


void gameLoop(SDL_Renderer *renderer, char *mapDir){
	// Constants
	int floorY = 8*(WINDOW_HEIGHT/9); // Where floor starts
	int frameDelay = 1000 / CAPPED_FPS; // Delay between frames

	// Gamestate
	char running = 1;
	char alive = 1;

	// Physics
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = floorY;
	int accelerate = 0;
	char grounded = 0;

	// Handling
	SDL_Event event; // Catch events
	Uint32 frameStart; // Tick of the first frame
	int frameTime; // Duration between first and last frames
	int totalFrames = 0;

	// Init of future (LL1) and alive (LL2) items
	char *levelFileUrl = malloc(strlen(mapDir) + strlen("map.level") + 1);
	sprintf(levelFileUrl, "%s/map.level", mapDir);
	LinkedList *LL1 = readFile(levelFileUrl);
	LinkedList *LL2 = NULL;
	LinkedList *tmpLL2;
	free(levelFileUrl);

	// Loading of first assets
	SDL_Texture *cubeTexture = loadImage(renderer, cube);
	SDL_Texture *groundTexture = loadImage(renderer, ground);
	SDL_Texture *bgTexture = loadImage(renderer, background);

	// Loading of items assets
	tmpLL2 = LL1;
	while (tmpLL2){
		tmpLL2->item->texture = loadImage(renderer, tmpLL2->item->type);
		tmpLL2 = tmpLL2->next;
	}



	while (running) {
		//* PRE-PROCESS
		frameStart = SDL_GetTicks();

		// If summon time, then pass to next list and check next item
		// Else we break, cause case won't be met latter on (check readme diagram)
		while (LL1){
			if (LL1->item->summon <= totalFrames){
				LLpush(&LL2, LLpop(&LL1));
			}	else { break; }
		}



		//* EVENT LOOP
		while (SDL_PollEvent(&event)){ // Event Handling
			switch (event.type){
				case SDL_QUIT:
					running = 0 ; break;
				case SDL_KEYDOWN:
					if (grounded){ accelerate = JUMP_FORCE; }
					break;
			}
		}



		//* PHYSIC LOOP
		// Move all items forward by 8 px
		tmpLL2 = LL2;
		while (tmpLL2){
			tmpLL2->item->posX -= 8;
			tmpLL2 = tmpLL2->next;
		}

		// Pop all items that are out of bounds (left, so gone)
		if (LL2){ liberationOfSpace(&LL2); }

		// Check if grounded, brings up above floor
		grounded = 0;
		if (YPosition > floorY) { // If below ground (then bring back up)
			YPosition = floorY;
			grounded = 1;
		} else if (YPosition == floorY) { // If at the ground
			grounded = 1;
		}

		tmpLL2 = LL2;
		while (tmpLL2){
			// If too far, then ignore
			if ((XPosition + BLOCK_SIZE) < tmpLL2->item->posX || XPosition > (tmpLL2->item->posX + BLOCK_SIZE)){
				tmpLL2 = tmpLL2->next;
				continue;
			}
			
			// We save 3 bools for state of collision
			//! This part of the code is messy, but modular conditions always are
			char borderRight = ( (XPosition + BLOCK_SIZE) >= tmpLL2->item->posX &&
			(((YPosition + BLOCK_SIZE) >= tmpLL2->item->posY && (YPosition <= tmpLL2->item->posY)) ||
			(YPosition + BLOCK_SIZE >= tmpLL2->item->posY + BLOCK_SIZE && (YPosition <= tmpLL2->item->posY + BLOCK_SIZE))) );
			char borderTop = (YPosition <= (tmpLL2->item->posY + BLOCK_SIZE) && (YPosition + SAFETY_MARGIN) >= (tmpLL2->item->posY + BLOCK_SIZE));
			char borderBot = ((YPosition + BLOCK_SIZE) <= tmpLL2->item->posY && (YPosition + BLOCK_SIZE + SAFETY_MARGIN) >= tmpLL2->item->posY);
			
			// Switch depending on type & state
			switch(tmpLL2->item->type){
				case square:
					if (borderBot){ // Collision with bottom border of player and top border of square
						grounded = 1; // We just grounded because square is safe
						YPosition = tmpLL2->item->posY - BLOCK_SIZE - SAFETY_MARGIN;
					} else if (borderTop || borderRight){ alive = 0; }
					break;
				case spikeUp:
				case spikeDown:
				case spikeLeft:
				case spikeRight:
					if (borderTop || borderRight || borderBot){ alive = 0; }
					break;
			} tmpLL2 = tmpLL2->next;
		}


		if (grounded && accelerate <= 0){
			accelerate = 0;
		} else {
			YPosition = YPosition - jumpTrajectory(&accelerate);
		}

		if (YPosition > floorY) { // If below ground (then bring back up)
			YPosition = floorY;
			grounded = 1;
		}

		//* RENDER LOOP
		// Only render 1/2 frames (game will run at 30 fps visually, to reduce lag)
		if (totalFrames % 2){
			// Clear renderer
			SDL_RenderClear(renderer);

			// Render default assets (bg, cube...)
			renderImage(renderer, bgTexture, (WINDOW_WIDTH + 300 - totalFrames % 2560), floorY, 2560, 720);
			renderImage(renderer, bgTexture, (WINDOW_WIDTH + 300 - totalFrames % 2560 + 2560), floorY, 2560, 720);
			renderImage(renderer, groundTexture, WINDOW_WIDTH+300, floorY+300, WINDOW_WIDTH+300, 300);
			renderImage(renderer, cubeTexture, XPosition, YPosition, BLOCK_SIZE, BLOCK_SIZE);

			// Render all items in LL2
			tmpLL2 = LL2;
			while (tmpLL2){
				renderImage(renderer, tmpLL2->item->texture, tmpLL2->item->posX, tmpLL2->item->posY, BLOCK_SIZE, BLOCK_SIZE);
				tmpLL2 = tmpLL2->next;
			}

			// Render the renderer
			SDL_RenderPresent(renderer);
		}



		//* POST-PROCESS
		// Delay between ticks
		frameTime = SDL_GetTicks() - frameStart; // Get delay between start and finish of loop
		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } // Delay the frame if needed
		totalFrames++; // Add one to total frames

		// If you lost, we stop the loop and so the game
		if (!alive) { running = 0; }
	}
}