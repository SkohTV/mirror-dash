#include "mainMenu.h"

void menuState(SDL_Renderer *renderer){

    // Menu States

    int posSelectorSquare = 1;
    int running = 1;
    SDL_Event event;

    // Loading of first assets

	SDL_Texture *cubeTexture = loadImage(renderer, cube);
	SDL_Texture *groundTexture = loadImage(renderer, ground);
	SDL_Texture *bgTexture = loadImage(renderer, background);
    SDL_Texture *PlayIconTexture = loadImage(renderer, playIcon);
    SDL_Texture *SkinIconTexture = loadImage(renderer, skinIcon);
    SDL_Texture *SettingsIconTexture = loadImage(renderer, settingsIcon);
    SDL_Texture *SelectorSquare1 = loadImage(renderer, SelectorSkinIcon);
    SDL_Texture *SelectorSquare2 = loadImage(renderer, SelectorPlayIcon);
    SDL_Texture *SelectorSquare3 = loadImage(renderer, SelectorSettingsIcon);

    // Event Manage
    while(running){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = 0;
                return;
            }
            else{
                if(event.type == SDL_KEYDOWN){
                    switch(event.key.keysym.sym){
                        case SDLK_KP_ENTER:
                        case SDLK_LEFT:
                            if(posSelectorSquare>=1){
                                posSelectorSquare-=1;
                            }
                        case SDLK_RIGHT:
                            if(posSelectorSquare<=1){
                                posSelectorSquare+=1;
                            }
                    }
                }
            }
        }
            // Rendering of menu assets

        SDL_RenderClear(renderer);

        renderImage(renderer, SkinIconTexture,1280,720,1280,720,0);
        renderImage(renderer, PlayIconTexture,0,0,1920,1080,0);
        renderImage(renderer, SettingsIconTexture,0,0,1920,1080,0);
    
        if(posSelectorSquare==0){
            renderImage(renderer, SelectorSquare1,0,0,1920,1080,0);
        }
        if(posSelectorSquare==1){
            renderImage(renderer, SelectorSquare2,0,0,1920,1080,0);
        }
        else{
            renderImage(renderer, SelectorSquare3,0,0,1920,1080,0);
        }


        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}


void test(){

}