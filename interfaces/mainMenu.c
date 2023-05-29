#include "mainMenu.h"

void menuState(SDL_Renderer *renderer){

    // Menu States

    int posSelectorSquare = 1;
    int skinChoosed = 0;
    int running = 1;
    SDL_Event event;

    // Loading of first assets

	SDL_Texture *cubeTexture0 = loadImage(renderer, cube);
    SDL_Texture *cubeTexture1 = loadImage(renderer, skin1);
    SDL_Texture *cubeTexture2 = loadImage(renderer, skin2);
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
                            if(posSelectorSquare==1){

                            }
                            break;
                        case SDLK_LEFT:
                            if(posSelectorSquare==1|| posSelectorSquare == 2){
                                posSelectorSquare-=1;
                            }
                            break;
                        case SDLK_RIGHT:
                            if(posSelectorSquare==1 || posSelectorSquare == 0){
                                posSelectorSquare+=1;
                            }
                            break;
                        case SDLK_UP:
                            if(posSelectorSquare==0 && skinChoosed<=1){
                                skinChoosed+=1;
                            }
                            break;
                        case SDLK_DOWN:
                            if(posSelectorSquare==0 && skinChoosed>=1){
                                skinChoosed-=1;
                            }
                            break;    
                    }
                }
            }
        }
            // Rendering of menu assets

        SDL_RenderClear(renderer);

        renderImage(renderer, bgTexture,1600,900,1600,900,0);
        renderImage(renderer, groundTexture,1600,1600,1600,900,0);
        if(skinChoosed==0){
            renderImage(renderer, cubeTexture0,600,700,80,80,0);
        }
        if(skinChoosed==1){
            renderImage(renderer, cubeTexture1,600,700,80,80,0);
        }
        if(skinChoosed==2){
            renderImage(renderer, cubeTexture2,600,700,80,80,0);
        }
        renderImage(renderer, SkinIconTexture,1600,900,1600,900,0);
        renderImage(renderer, PlayIconTexture,1600,900,1600,900,0);
        renderImage(renderer, SettingsIconTexture,1600,900,1600,900,0);
    
        if(posSelectorSquare==0){
            renderImage(renderer, SelectorSquare1,1600,900,1600,900,0);
        }
        if(posSelectorSquare==1){
            renderImage(renderer, SelectorSquare2,1600,900,1600,900,0);
        }
        if(posSelectorSquare==2){
            renderImage(renderer, SelectorSquare3,1600,900,1600,900,0);
        }


        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}


void test(){

}