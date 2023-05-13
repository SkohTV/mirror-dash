#include "gameLoop.h"
#include "../primitives/core.h"
#include "../primitives/fileCreator.h"


void gameLoop(SDL_Renderer *renderer, char *mapDir){
	// CONSTANTS
	int floorY = 8*(WINDOW_HEIGHT/9); // Where floor starts
	int frameDelay = 1000 / CAPPED_FPS; // Delay between frames
	printf("%d\n", floorY);

	// GAMESTATE
	int running = 1;

	// Physics
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = floorY;
	double accelerate = 0;
	char grounded = 0;


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
	tmpLL2 = LL1;
	while (tmpLL2){
		tmpLL2->item->texture = loadImage(renderer, tmpLL2->item->type);
		tmpLL2 = tmpLL2->next;
	}
	SDL_Texture *cubeTexture = loadImage(renderer, cube);
	SDL_Texture *backgroundTexture = loadImage(renderer, background);

	while (running) {
		//* PRE-PROCESS
		frameStart = SDL_GetTicks();


		// If summon time, then pass to next list and check next item
		// Else go next
		while (LL1){
			if (LL1->item->summon <= totalFrames){
				LLpush(&LL2, LLpop(&LL1));
			}	else { break; }
		}

		tmpLL2 = LL2;
		while (tmpLL2){
			tmpLL2->item->posX -= 13;
			tmpLL2 = tmpLL2->next;
		}

		if (LL2){ liberationOfSpace(&LL2); }

		//LinkedList tmpLL2 = LL2;
		//int a = 0;
		//while(tmpLL2){
		//	printf("Keep %d : %d\n", a++, tmpLL2->item->posX);
		//	if (tmpLL2->item->posX <= -BLOCK_SIZE){
		//		//printf("Throw : %d\n", tmpLL2->item->posX);
		//		LLpop(&alterLL2);
		//	} else {
		//		(tmpLL2) = (tmpLL2)->next;
		//	} 
		//} LL2 = tmp;


		//tmpLL2 = LL2;
		//while (tmpLL2){
		//	if (tmpLL2->item->posX > WINDOW_WIDTH){
		//		LLpop(&tmpLL2);
		//		break;
		//	} else { tmpLL2 = tmpLL2->next; }
		//}

		



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
		// Check if grounded, brings up above floor
		if (YPosition > floorY) { // If below ground (then bring back up)
			YPosition = floorY;
			grounded = 1;
		} else if (YPosition == floorY) { // If at the ground
			grounded = 1;
		} else { grounded = 0; } // If above ground

		if (grounded && accelerate <= 0){
			accelerate = 0.0;
		} else {
			YPosition = YPosition - jumpTrajectory(&accelerate);
		}




		//* RENDER LOOP

		SDL_RenderClear(renderer);

		if (totalFrames%2){
		tmpLL2 = LL2;
		while (tmpLL2){
			renderImage(renderer, tmpLL2->item->texture, tmpLL2->item->posX, tmpLL2->item->posY, 80, 80);
			tmpLL2 = tmpLL2->next;
		}

		renderImage(renderer, cubeTexture, XPosition, YPosition, 80, 80);
		//SDL_SetRenderTarget(renderer, NULL); // Renderer becames default target
		renderImage(renderer, backgroundTexture, 1280, floorY+300, 1280, 300);
		renderImage(renderer, backgroundTexture, 1280+300, floorY+300, 1280, 300);
		SDL_RenderPresent(renderer);
}

		//* POST-PROCESS
		frameTime = SDL_GetTicks() - frameStart; // Get delay between start and finish of loop
		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } // Delay the frame if needed
		totalFrames++; // Add one to total frames
		if (totalFrames % 60 == 0) {printf("%d\n", totalFrames/60);}
	}
}


/*
Gérer le scroll du background & la musique
Mouvement automatique du joueur
*/

/*
Contact avec le 'sol'(barre du milieu)
Contact avec un obstacle:
	- piques, murs
	- pads, boules de sauts
Eventuellement, sortie de map ? 

*/