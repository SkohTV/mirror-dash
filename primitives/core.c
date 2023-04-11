#include "core.h"



void startSDL(){
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n",
		SDL_GetError());
		exit(EXIT_FAILURE); // On quitte le programme
	}
}


int closeSDL(){
	SDL_Quit ();
	return EXIT_SUCCESS;
}


int createWindow(SDL_Window **window, SDL_Renderer **renderer){
	if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN, window, renderer) != 0){
		fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
		return EXIT_FAILURE;
	} else{
		return EXIT_SUCCESS;
	}
}


int freeWindow(SDL_Window *window, SDL_Renderer *renderer){
	if(NULL != renderer){
		SDL_DestroyRenderer(renderer);
	}	if(NULL != window){
		SDL_DestroyWindow(window);
		SDL_Quit ();
		printf("Quit\n");
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}


void loadImage(SDL_Renderer *renderer, char shape, int X, int Y){
	SDL_Texture *texture = NULL;
	SDL_Surface *surface = NULL;
	if ( renderer == NULL ){
		fprintf(stderr, "Echec de creation du renderer : %s", SDL_GetError());
	}	else {
		switch (shape){
			case 0:
				surface = IMG_Load("assets/skins/base.png");
				break;
		}
		if (surface == NULL ){
			fprintf(stderr, "Echec de chargement du fichier : %s ", SDL_GetError());
	}	else {
			//SDL_SetColorKey ( surface, SDL_TRUE, 0x000000 );
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (texture == NULL){
				fprintf(stderr, "Echec de creation de la texture : %s", SDL_GetError());
			}	else {
				SDL_Rect dest = {
					X - surface->w/2,
					Y - surface->h/2,
					surface->w,
					surface->h
				};//un SDL_Rect qui sert de destination à l'image
				SDL_SetRenderTarget(renderer, texture); // la texture devient la cible du rendu
				SDL_RenderCopy(renderer, texture, NULL, &dest); // on dessine sur la texture
				SDL_DestroyTexture(texture);// destruction de la texture
			}// fin texture non nulle
			SDL_FreeSurface (surface); // liberation de la mémoire allouée pour la surface
		} // Fin surface non nulle
	}// fin renderer non nul
	SDL_SetRenderTarget(renderer, NULL); // le renderer devient la cible du rendu par default
	SDL_RenderPresent(renderer);
}


void eventHandler(SDL_Renderer *renderer){
	int continuer = 1;
	SDL_Event event;
	while (continuer) {
		SDL_WaitEvent (&event); // attente d'un évènement
		float start = 25.0;
		int XPosition = WINDOW_WIDTH/2;
		int YPosition = WINDOW_HEIGHT/2;
		switch (event.type) {
			case SDL_QUIT :
				continuer = 0;
				break;
			case SDL_MOUSEBUTTONDOWN :
				YPosition = YPosition - (int)jumpTrajectory(&start);
				while (YPosition < WINDOW_HEIGHT/2){
					SDL_RenderClear(renderer);
					loadImage(renderer, 0, XPosition, YPosition);
					YPosition = YPosition - (int)jumpTrajectory(&start);
				}
		}
	}
}

//TODO Will be changed to fixed point integer
int jumpTrajectory(float *accelerate){
	(*accelerate) = (*accelerate) - 1;
	return (int)(*accelerate);
}