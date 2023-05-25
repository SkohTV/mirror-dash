#include "mainMenu.h"

void menuState(){

	// Menu States

	onPlayIcon = 1;
	onSkinIcon = 2;
	onSettingsIcon = 3;
	posSelectorSquare = 0;

	// Loading of first assets

	SDL_Texture *cubeTexture = loadImage(renderer, cube);
	SDL_Texture *groundTexture = loadImage(renderer, ground);
	SDL_Texture *bgTexture = loadImage(renderer, background);
	SDL_Texture *PlayIconTexture = loadImage(renderer, ?);
	SDL_Texture *SkinIconTexture = loadImage(renderer, ?);
	SDL_Texture *SettingsIconTexture = loadImage(renderer, ?);
	SDL_Texture *SelectorSquare = loadImage(renderer, ?);

	// Rendering of menu assets

	SDL_RenderClear();

	renderImage(renderer, SkinIconTexture,);
	renderImage(renderer, PlayIconTexture,);
	renderImage(renderer, SettingsIconTexture,);

	// Event Manage

	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			break;
		}
		else{
			if(event.type == SDL_KEYDOWN){
				switch(event.key.keysym.sym)){
					case SDLK_ENTER:
					case SDLK_LEFT:
					case SDLK_RIGHT:
				}
			}

		}
	}
}


void test(){

}