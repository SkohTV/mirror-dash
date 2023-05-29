#include "gameLoop.h"
#include "../primitives/core.h"
#include "../primitives/fileCreator.h"
#include "../primitives/playerMovements.h"
#include "../primitives/particles.h"


int gameLoop(SDL_Renderer *renderer, char *mapDir, char skin){
	// Constants
	int floorY = 8*(WINDOW_HEIGHT/9)+150; // Where floor starts
	Uint32 frameDelay = 1000 / CAPPED_FPS; // Delay between frames
	int DEFAULT_floorY = floorY; // Static, will never change 

	// Gamestate
	char running = 1;
	char alive = 1;
	char close = 0;

	// Physics
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = floorY;
	int accelerate = 0;
	char gravity = 1;
	char grounded = 0;
	char spacePressed = 0;

	// Handling
	SDL_Event event; // Catch events
	Uint32 frameStart; // Tick of the first frame
	Uint32 frameTime; // Duration between first and last frames
	int totalFrames = 0;
	int remaining;

	// Init of future (LL1) and alive (LL2) items
	char *levelFileUrl = malloc(strlen(mapDir) + strlen("map.level") + 1);
	sprintf(levelFileUrl, "%s/map.level", mapDir);
	LinkedList *LL1 = readFile(levelFileUrl);
	LinkedList *LL2 = NULL;
	LinkedList *tmpLL2;
	free(levelFileUrl);

	// Loading of first assets
	SDL_Texture *cubeTexture = loadImage(renderer, skin);
	SDL_Texture *groundTexture = loadImage(renderer, ground);
	SDL_Texture *bgTexture;
	if (strcmp(mapDir, "assets/maps/first") == 0) bgTexture = loadImage(renderer, background1);
	else if (strcmp(mapDir, "assets/maps/second") == 0) bgTexture = loadImage(renderer, background2);
	else if (strcmp(mapDir, "assets/maps/third") == 0) bgTexture = loadImage(renderer, background3);

	// Loading of items assets
	int end;
	tmpLL2 = LL1;
	while (tmpLL2){
		tmpLL2->item->texture = loadImage(renderer, tmpLL2->item->type);
		end = tmpLL2->item->summon + 104; // 100 is frames between summon time and collision
		tmpLL2 = tmpLL2->next;
	}

	// Linked List for particles
	ItemParticle *particle = NULL;
	int particleCount = 0;


	// Init the sound
	char *soundFileUrl = malloc(strlen(mapDir) + strlen("music.mp3") + 1);
	sprintf(soundFileUrl, "%s/music.mp3", mapDir);
	Mix_Music *soundItem = loadSound(soundFileUrl);
	playSound(soundItem);



	while (running) {
		//* PRE-PROCESS
		frameStart = SDL_GetTicks();

		if (totalFrames >= end){
			running = 0;
		}

		// If summon time, then pass to next list and check next item
		// Else we break, cause case won't be met latter on (check readme diagram)
		while (LL1){
			if (LL1->item->summon <= totalFrames){
				LLpush(&LL2, LLpop(&LL1));
			}	else { break; }
		}



		//* EVENT LOOP
		spacePressed = 0;

		while (SDL_PollEvent(&event)){ // Event Handling
			switch (event.type){
				case SDL_QUIT:
					running = 0;
					alive = 0;
					close = 1;
					break;
				case SDL_KEYDOWN:
					if (grounded) playerJump(&accelerate, gravity);
					spacePressed = 1;
					break;
			}
		}



		//* PHYSIC LOOP
		// You are not grounded anymore
		grounded = 0;


		// Move all items forward by 8 px
		tmpLL2 = LL2;
		while (tmpLL2){
			tmpLL2->item->posX -= 8;
			tmpLL2 = tmpLL2->next;
		}

		// Pop all items that are out of bounds (left, so gone)
		if (LL2){ liberationOfSpace(&LL2); }

		// Check if grounded, brings up above floor
		if ((YPosition >= floorY && gravity == 1) || (YPosition <= floorY && gravity == -1)) { // If below ground (then bring back up)
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
			char borderRight = ( ((XPosition + BLOCK_SIZE) >= tmpLL2->item->posX) && 
			(((YPosition + BLOCK_SIZE) >= tmpLL2->item->posY && (YPosition <= tmpLL2->item->posY)) ||
			(YPosition + BLOCK_SIZE >= tmpLL2->item->posY + BLOCK_SIZE && (YPosition <= (tmpLL2->item->posY + BLOCK_SIZE)))) );
			char borderTop = ((YPosition < (tmpLL2->item->posY + BLOCK_SIZE)) && ((YPosition + BLOCK_SIZE) >= (tmpLL2->item->posY + BLOCK_SIZE)));
			char borderBot = ((YPosition < tmpLL2->item->posY) && ((YPosition + BLOCK_SIZE) >= tmpLL2->item->posY));


			// 2 other states, only used for specific checks
			char lowHeightBorderRight = ( ((XPosition + BLOCK_SIZE) >= (tmpLL2->item->posX + LOW_BLOCK_SIZE)) && 
			(((YPosition + BLOCK_SIZE) >= (tmpLL2->item->posY + LOW_BLOCK_SIZE) && (YPosition <= (tmpLL2->item->posY + LOW_BLOCK_SIZE))) ||
			((YPosition + BLOCK_SIZE) >= (tmpLL2->item->posY + BLOCK_SIZE) && (YPosition <= (tmpLL2->item->posY + BLOCK_SIZE)))) );
			char lowBorderTop = (YPosition >= floorY-30 && gravity == 1) || (YPosition <= floorY+30 && gravity == -1);
			// Switch depending on type & state
			switch(tmpLL2->item->type){
				case square:
					if (borderBot){ // Collision with bottom border of player and top border of square
						grounded = 1; // We just grounded because square is safe
						YPosition = tmpLL2->item->posY - BLOCK_SIZE;
					} else if (borderTop || borderRight){ alive = 0; }
					break;
				case spikeUp:
				case spikeDown:
				case spikeLeft:
				case spikeRight:
					if (borderTop || borderRight || borderBot) alive = 0;
					break;
				case gravityPadUp:
				case gravityPadDown:
					if (lowBorderTop && lowHeightBorderRight) reverseGravity(&gravity, &floorY, &accelerate, &grounded);
					break;
				case gravityCircle:
					if ((borderTop || borderBot) && (borderRight) && (spacePressed)) reverseGravity(&gravity, &floorY, &accelerate, &grounded);
					break;
				case jumpPadUp:
				case jumpPadDown:
					if (lowBorderTop && lowHeightBorderRight) playerJump(&accelerate, gravity);
					break;
				case jumpCircle:
					if ((borderTop || borderBot) && (borderRight) && (spacePressed)) playerJump(&accelerate, gravity);
					break;
			} tmpLL2 = tmpLL2->next;
		}


		if (grounded && ((accelerate <= 0 && gravity == 1) || (accelerate >= 0 && gravity == -1))){
			accelerate = 0;
		} else {
			YPosition = YPosition - jumpTrajectory(&accelerate, gravity);
		}


		if ((YPosition > floorY && gravity == 1) || (YPosition < floorY && gravity == -1)) { // If below ground (then bring back up)
			YPosition = floorY;
			grounded = 1;
		}

		//* RENDER LOOP

		// Only render 1/2 frames (game will run at 30 fps visually, to reduce lag)
		if (totalFrames % 2){
			// Clear renderer
			SDL_RenderClear(renderer);

			// Render default assets (bg, cube...)
			renderImage(renderer, bgTexture, (WINDOW_WIDTH + 300 - totalFrames % 2560), DEFAULT_floorY, 2560, 720, 0);
			renderImage(renderer, bgTexture, (WINDOW_WIDTH + 300 - totalFrames % 2560 + 2560), DEFAULT_floorY, 2560, 720, 0);
			renderImage(renderer, groundTexture, WINDOW_WIDTH+300, DEFAULT_floorY+300, WINDOW_WIDTH+300, 300, 0);
			renderImage(renderer, groundTexture, WINDOW_WIDTH+300, 70, WINDOW_WIDTH+300, 300, 1);

			// Render all items in LL2
			tmpLL2 = LL2;
			while (tmpLL2){
				if (tmpLL2->item->type == endOfGame) renderImage(renderer, tmpLL2->item->texture, tmpLL2->item->posX, DEFAULT_floorY, 120, DEFAULT_floorY-70, 0);
				else renderImage(renderer, tmpLL2->item->texture, tmpLL2->item->posX, tmpLL2->item->posY, BLOCK_SIZE, BLOCK_SIZE, 0);
				tmpLL2 = tmpLL2->next;
			}

			// Change drawing color
			if (skin == skin1) SDL_SetRenderDrawColor(renderer, 68, 139, 10, 120);
			else if (skin == skin2) SDL_SetRenderDrawColor(renderer, 197, 69, 10, 120);
			else if (skin == skin3) SDL_SetRenderDrawColor(renderer, 0, 162, 232, 120);

			// Draw particles
			if (!grounded && gravity == 1) Ppush(&particle, XPosition - BLOCK_SIZE, YPosition - 10);
			else if (!grounded && gravity == -1) Ppush(&particle, XPosition - BLOCK_SIZE, YPosition - BLOCK_SIZE + 10);
			else Ppush(&particle, 0, 0);
			particleCount++;
			Pdraw(renderer, &particle, &particleCount);

			// Draw and calculate time remaining
			SDL_SetRenderDrawColor(renderer, 178, 34, 34, 255); // Change drawing color
			remaining = (totalFrames * 500 / end) + 1;
			SDL_Rect rect = {500, 15, 500, 20}; // Red bar
			SDL_RenderFillRect(renderer, &rect);

			SDL_SetRenderDrawColor(renderer, 129, 182, 34, 255); // Change drawing color
			SDL_Rect rect2 = {500, 15, remaining, 20}; // Green bar
			SDL_RenderFillRect(renderer, &rect2);

			// Reset drawing color
			SDL_SetRenderDrawColor(renderer, 117, 117, 117, 255);

			// Draw cube at the end
			renderImage(renderer, cubeTexture, XPosition, YPosition, BLOCK_SIZE, BLOCK_SIZE, (gravity < 0));

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


	//* END OF GAME
	freeSound(soundItem);
	if (close) return -1;
	return alive;
}


int gameInterface(SDL_Renderer *renderer, char *mapDir, char skin){
	char res = gameLoop(renderer, mapDir, skin);

	if (res == -1) return -1;

	SDL_Texture *texture = NULL;

	if (res) texture = loadImage(renderer, winIcon);
	else texture = loadImage(renderer, loseIcon);

	SDL_SetRenderDrawColor(renderer, 117, 117, 117, 100);
	SDL_Rect rect = {0, 0, 2000, 1200};
	SDL_RenderFillRect(renderer, &rect);
	renderImage(renderer, texture, 1000, 650, 500, 500, 0);
	SDL_SetRenderDrawColor(renderer, 117, 117, 117, 255);
	SDL_RenderPresent(renderer);

	int running = 1;
	SDL_Event event;
	int frameStart;
	int frameTime;
	int totalFrames = 0;
	int frameDelay = 1000 / CAPPED_FPS;
	int remaining = 120;

	while (running){
		frameStart = SDL_GetTicks();

		if (totalFrames >= remaining) running = 0;

		while (SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT) running = 0;
		}

		frameTime = SDL_GetTicks() - frameStart; // Get delay between start and finish of loop
		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } // Delay the frame if needed
		totalFrames++; // Add one to total frames
	}

	return 1;
}