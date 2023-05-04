#include "gameLoop.h"
#include "../primitives/core.h"


void gameLoop(SDL_Renderer *renderer){
	// CONSTANTS
	int floorY = 8*(WINDOW_HEIGHT/9); // Where floor starts
	int frameDelay = 1000 / CAPPED_FPS; // Delay between frames

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


	while (running) {
		//* PRE-PROCESS
		frameStart = SDL_GetTicks();


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
		loadImage(renderer, cube, XPosition, YPosition);
		SDL_SetRenderTarget(renderer, NULL); // Renderer becames default target
		SDL_RenderPresent(renderer);


		//* POST-PROCESS
		frameTime = SDL_GetTicks() - frameStart; // Get delay between start and finish of loop
		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } // Delay the frame if needed
		totalFrames++; // Add one to total frames
		//if (totalFrames % 60 == 0) {printf("%d\n", totalFrames/60);}
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