#include "gameLoop.h"
#include "../primitives/core.h"


void eventHandler(SDL_Renderer *renderer){
	int running = 1; // Si la fenêtre est fermée ou pas
	SDL_Event event; // Récupère les events
	float currentJumpForce = JUMP_FORCE;
	
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = WINDOW_HEIGHT/2;
	
	while (running) {
		SDL_PollEvent(&event); // New and improved
		Uint64 start = SDL_GetPerformanceCounter();
		
		switch (event.type) { // Event Handling
			case SDL_QUIT :
				running = 0; break;
			case SDL_MOUSEBUTTONDOWN :
				YPosition = YPosition - (int)jumpTrajectory(&start); break;
		}

		SDL_RenderClear(renderer);
		loadImage(renderer, 0, XPosition, YPosition);

		Uint64 end = SDL_GetPerformanceCounter();
		float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(floor(16.666f - elapsedMS)); // Cap to 60 FPS
	}
}


/*
Cap les fps
Récupérer les events et les vérifier
Gérer le scroll du background & la musique
Les projectiles ?
Mouvement automatique du joueur
*/

/*
Contact avec le 'sol'(barre du milieu)
Contact avec un obstacle:
	- piques, murs, projectiles
	- pads, boost, boules de sauts, portails ?
Eventuellement, sortie de map ? 

*/