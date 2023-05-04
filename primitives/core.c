#include "core.h"



void startSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Error: Cannot init SDL -> %s\n",
		SDL_GetError());
		exit(EXIT_FAILURE); // We leave the program
	}
}


int createWindow(SDL_Window **window, SDL_Renderer **renderer){
	int res = SDL_CreateWindowAndRenderer(
			// Window size
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			// Flags
			SDL_RENDERER_ACCELERATED | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS,
			// BOTH MUST BE PASSED HERE
			window,
			renderer
		);
	if(res != 0){
		fprintf(stderr, "Error: SDL_CreateWindowAndRenderer -> %s", SDL_GetError());
		return EXIT_FAILURE;
	} else { return EXIT_SUCCESS; }
}


//! Closes the window
int closeSDL(SDL_Window *window, SDL_Renderer *renderer){
	if(NULL != renderer){
		SDL_DestroyRenderer(renderer);
	}	 else { return EXIT_FAILURE; }
	if(NULL != window){
		SDL_DestroyWindow(window);
		SDL_Quit (); // Closes here
		printf("Quit\n");
		return EXIT_SUCCESS;
	} else { return EXIT_FAILURE; }
}


void loadImage(SDL_Renderer *renderer, char shape, int X, int Y){
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;
	if ( renderer == NULL ){
		fprintf(stderr, "Error: Cannot create renderer -> %s", SDL_GetError());
	}	else {
		switch (shape){
			case cube:
				surface = IMG_Load("assets/skins/base.png");
				break;
			case background:
				break;
			case square:
				surface = IMG_Load("assets/blocks/square.png");
				break;
		}
		if (surface == NULL ){
			fprintf(stderr, "Error: Cannot load file -> %s ", SDL_GetError());
	}	else {
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (texture == NULL){
				fprintf(stderr, "Error: Cannot create texture -> %s", SDL_GetError());
			}	else {
				SDL_Rect dest = {
					X - surface->w/2,
					Y - surface->h/2,
					surface->w,
					surface->h
				}; // SDL_Rect serves as a location for the image
				SDL_SetRenderTarget(renderer, texture); // Texture becames target of renderer
				SDL_RenderCopy(renderer, texture, NULL, &dest); // Draw texture to canva
				SDL_DestroyTexture(texture); // Destroy the texture
			}//* End of null texture
			SDL_FreeSurface (surface); // Free alocated memory for surface
		} // End of null surface
	}// End of null renderer
}


int jumpTrajectory(double *accelerate){
	(*accelerate) = (*accelerate) - 1;
	return (int)(*accelerate);
}