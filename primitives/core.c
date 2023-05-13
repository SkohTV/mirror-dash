#include "core.h"
#include "linkedList.h"



void startSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Error: Cannot init SDL -> %s\n",
		SDL_GetError());
		exit(EXIT_FAILURE); // We leave the program
	}
}


int createWindow(SDL_Window **window, SDL_Renderer **renderer){
	(*window) = SDL_CreateWindow(
		"Mirror Dash",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_MAXIMIZED | SDL_WINDOW_OPENGL
	);
	(*renderer) = SDL_CreateRenderer(
		*window,
		-1,
		SDL_RENDERER_ACCELERATED
	);
	return EXIT_SUCCESS;
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


SDL_Texture *loadImage(SDL_Renderer *renderer, char shape){
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
				surface = IMG_Load("assets/blocks/ground.png");
				break;
			case square:
				surface = IMG_Load("assets/blocks/square.png");
				//surface = IMG_Load("assets/skins/base.png");
				break;
		}
		if (surface == NULL ){
			fprintf(stderr, "Error: Cannot load file -> %s ", SDL_GetError());
	}	else {
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (texture == NULL){
				fprintf(stderr, "Error: Cannot create texture -> %s", SDL_GetError());
			} //* End of null texture
			SDL_FreeSurface (surface); // Free alocated memory for surface
			return texture;
		} // End of null surface
	} // End of null renderer
}


void renderImage(SDL_Renderer *renderer ,SDL_Texture *texture, int X, int Y, int W, int H){
	if (texture == NULL){ printf("Error while rendering texture\n"); }
	SDL_Rect dest = { X - W, Y - H, W, H }; // SDL_Rect define the position of the image
	SDL_RenderCopy(renderer, texture, NULL, &dest); // Draw texture to canva
}


int jumpTrajectory(double *accelerate){
	(*accelerate) = (*accelerate) - 1;
	return (int)(*accelerate);
}