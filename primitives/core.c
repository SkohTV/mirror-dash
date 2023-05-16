#include "core.h"
#include "linkedList.h"



// This should never crash under any circumstance
// Else, that would mean big problems
void startSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Error: Cannot init SDL -> %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
}


// Create window AND renderer
// Passed by arguments so no return
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
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	return EXIT_SUCCESS;
}


//! Closes the window
int closeSDL(SDL_Window *window, SDL_Renderer *renderer){
	if(NULL != renderer){ // Destroy renderer here
		SDL_DestroyRenderer(renderer);
	}	 else { return EXIT_FAILURE; }
	if(NULL != window){ // Destroy window here
		SDL_DestroyWindow(window);
		SDL_Quit(); // Closes here
		printf("Quit\n");
		return EXIT_SUCCESS;
	} else { return EXIT_FAILURE; }
}


SDL_Texture *loadImage(SDL_Renderer *renderer, char shape){
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;
	if ( renderer == NULL ){
		fprintf(stderr, "Error: Cannot create renderer -> %s", SDL_GetError());
		return NULL;
	}	else {
		switch (shape){ // Load items depending of the choosen shape
			case cube: surface = IMG_Load("assets/skins/base.png") ; break ;
			case background: surface = IMG_Load("assets/blocks/background.png") ; break ;
			case ground: surface = IMG_Load("assets/blocks/ground.png") ; break ;
			case square: surface = IMG_Load("assets/blocks/square.png") ; break ;
			case spikeUp: surface = IMG_Load("assets/blocks/spikeUp.png") ; break ;
			case spikeDown: surface = IMG_Load("assets/blocks/spikeDown.png") ; break ;
			case spikeLeft: surface = IMG_Load("assets/blocks/spikeLeft.png") ; break ;
			case spikeRight: surface = IMG_Load("assets/blocks/spikeRight.png") ; break ;
			case gravityPad: surface = IMG_Load("assets/blocks/gravityPad.png") ; break ;
			case gravityCircle: surface = IMG_Load("assets/blocks/gravityCircle.png") ; break ;
			case jumpPad: surface = IMG_Load("assets/blocks/jumpPad.png") ; break ;
			//case jumpCircle: surface = IMG_Load("assets/blocks/jumpCircle.png") ; break ;
		}
		if (surface == NULL ){
			fprintf(stderr, "Error: Cannot load file -> %s ", SDL_GetError());
			return NULL;
	}	else {
			texture = SDL_CreateTextureFromSurface(renderer, surface); // Cannot use surface, so convert to texture
			if (texture == NULL){
				fprintf(stderr, "Error: Cannot create texture -> %s", SDL_GetError());
			} //* End of null texture
			SDL_FreeSurface(surface);
			return texture; // Return the texture for caching purposes
		} // End of null surface
	} // End of null renderer
}


void renderImage(SDL_Renderer *renderer ,SDL_Texture *texture, int X, int Y, int W, int H){
	if (texture == NULL){ printf("Error while rendering texture\n"); }
	SDL_Rect dest = { X - W, Y - H, W, H }; // SDL_Rect define the position of the image
	SDL_RenderCopy(renderer, texture, NULL, &dest); // Draw texture to renderer
}


//? We don't need to much of a complexe script, since it's just vertical jump
int jumpTrajectory(int *accelerate){
	(*accelerate) = (*accelerate) - 1;
	return (*accelerate);
}