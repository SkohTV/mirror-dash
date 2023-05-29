#include "core.h"
#include "linkedList.h"



// This should never crash under any circumstance
// Else, that would mean big problems
void startSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		fprintf(stderr, "Error: Cannot init SDL -> %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	if (Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640) != 0){
		fprintf(stderr, "Error: Cannot init SDL_mixer -> %s\n", Mix_GetError());
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
	MixQuit(); // Kill audio
	SDL_DestroyRenderer(renderer); // Kill renderer
	SDL_DestroyWindow(window); // Kill window
	SDL_Quit(); // Kill subsystems
	return EXIT_SUCCESS;
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
			case gravityPadUp: surface = IMG_Load("assets/blocks/gravityPadUp.png") ; break ;
			case gravityPadDown: surface = IMG_Load("assets/blocks/gravityPadDown.png") ; break ;
			case gravityCircle: surface = IMG_Load("assets/blocks/gravityCircle.png") ; break ;
			case jumpPadUp: surface = IMG_Load("assets/blocks/jumpPadUp.png") ; break ;
			case jumpPadDown: surface = IMG_Load("assets/blocks/jumpPadDown.png") ; break ;
			case jumpCircle: surface = IMG_Load("assets/blocks/jumpCircle.png") ; break ;
			case endOfGame: surface = IMG_Load("assets/blocks/endBar.png") ; break ;
			case playIcon: surface = IMG_Load("assets/gui/menu_playIcon.png") ; break ;
			case settingsIcon: surface = IMG_Load("assets/gui/menu_settingsIcon.png") ; break ;
			case skinIcon: surface = IMG_Load("assets/gui/menu_skinIcon.png") ; break ;
			case SelectorPlayIcon: surface = IMG_Load("assets/gui/selectorOnPlayIcon.png") ; break ;
			case SelectorSettingsIcon: surface = IMG_Load("assets/gui/selectorOnSettingsIcon.png") ; break ;
			case SelectorSkinIcon: surface = IMG_Load("assets/gui/selectorOnSkinIcon.png") ; break ;
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


void renderImage(SDL_Renderer *renderer ,SDL_Texture *texture, int X, int Y, int W, int H, char flip){
	if (texture == NULL){ fprintf(stderr, "Error while rendering texture\n"); }
	SDL_Rect dest = { X - W, Y - H, W, H }; // SDL_Rect define the position of the image
	char flag = flip ? SDL_FLIP_VERTICAL : SDL_FLIP_NONE; // Set flip flag
	SDL_RenderCopyEx(renderer, texture, NULL, &dest, 0.0, NULL, flag); // Draw texture to renderer
}


int initSound(){
	int result = 0;

	if (SDL_Init(SDL_INIT_AUDIO) < 0) {
		fprintf(stderr, "Failed to init SDL\n");
		return EXIT_FAILURE;
	}

	if (MIX_INIT_MP3 != (result = Mix_Init(MIX_INIT_MP3))) {
		fprintf(stderr, "Could not initialize mixer (result: %d)\n", result);
		fprintf(stderr, "Mix_Init: %s\n", Mix_GetError());
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


Mix_Music *loadSound(char *path){
	Mix_Music *music = Mix_LoadMUS(path);
	return music;
}


int playSound(Mix_Music *music){
	Mix_PlayMusic(music, 1);
	return EXIT_SUCCESS;
}


int freeSound(Mix_Music *music){
	Mix_FreeMusic(music);
	return EXIT_SUCCESS;
}