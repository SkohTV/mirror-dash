#include "mainMenu.h"


void menuState(){
	startSDL();
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	createWindow(&window, &renderer);
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderClear(renderer);

	// For background
	Uint32 frameStart;
	Uint32 frameTime;
	Uint32 frameDelay = 1000 / CAPPED_FPS;
	int totalFrames = 0;
	int defaultFloorY = 8*(WINDOW_HEIGHT/9)+150;

	// Menu States
	int posSelectorSquare = 1;
	int skinChoosed = 0;
	int mapChoosed = 0;
	int running = 1;
	int volume = MIX_MAX_VOLUME / 2;
	volumeDown(&volume);
	SDL_Event event;

	// Loading of first assets
	SDL_Texture *cubeTexture0 = loadImage(renderer, skin1);
	SDL_Texture *cubeTexture1 = loadImage(renderer, skin2);
	SDL_Texture *cubeTexture2 = loadImage(renderer, skin3);
	SDL_Texture *groundTexture = loadImage(renderer, ground);
	SDL_Texture *bgTexture0 = loadImage(renderer, background1);
	SDL_Texture *bgTexture1 = loadImage(renderer, background2);
	SDL_Texture *bgTexture2 = loadImage(renderer, background3);
	SDL_Texture *PlayIconTexture = loadImage(renderer, playIcon);
	SDL_Texture *SkinIconTexture = loadImage(renderer, skinIcon);
	SDL_Texture *SettingsIconTexture = loadImage(renderer, settingsIcon);
	SDL_Texture *SelectorSquare1 = loadImage(renderer, SelectorSkinIcon);
	SDL_Texture *SelectorSquare2 = loadImage(renderer, SelectorPlayIcon);
	SDL_Texture *SelectorSquare3 = loadImage(renderer, SelectorSettingsIcon);

	SDL_Texture *currentSkin = cubeTexture0;
	SDL_Texture *currentMap = bgTexture0;

	Mix_Music *soundItem = loadSound("assets/gui/default.mp3");
	playSound(soundItem);



	// Main loop
	while(running){

		//* PRE PROCESS
		frameStart = SDL_GetTicks();



		//* EVENT LOOP
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = 0;
				return;
			}

			// Don't care about keydown
			if(event.type != SDL_KEYDOWN) continue;

			switch(event.key.keysym.sym){
				case SDLK_SPACE:
					if (posSelectorSquare==1){
						freeSound(soundItem);
						char tmpSkin = !skinChoosed ? skin1 : skinChoosed==1 ? skin2 : skin3;
						switch (mapChoosed){
							case 0: gameInterface(renderer, "assets/maps/first", tmpSkin) ; break ;
							case 1: gameInterface(renderer, "assets/maps/second", tmpSkin) ; break ;
							case 2: gameInterface(renderer, "assets/maps/third", tmpSkin) ; break ;
						} SDL_Delay(300);
						soundItem = loadSound("assets/gui/default.mp3");
						playSound(soundItem);
					} break;
				case SDLK_LEFT: if (posSelectorSquare==1|| posSelectorSquare == 2) posSelectorSquare-=1 ; break ;
				case SDLK_RIGHT: if (posSelectorSquare==1 || posSelectorSquare == 0) posSelectorSquare+=1 ; break ;
				case SDLK_UP:
					if (posSelectorSquare==0 && skinChoosed<=1) skinChoosed+=1;
					if (posSelectorSquare==1 && mapChoosed<=1) mapChoosed+=1;
					if (posSelectorSquare==2 && volume < 100) volumeUp(&volume);
					break;
				case SDLK_DOWN:
					if (posSelectorSquare==0 && skinChoosed>=1) skinChoosed-=1;
					if (posSelectorSquare==1 && mapChoosed>=1) mapChoosed-=1;
					if (posSelectorSquare==2 && volume > 0) volumeDown(&volume);
					break;    
			}
			if (skinChoosed==0) currentSkin=cubeTexture0;
			if (skinChoosed==1) currentSkin=cubeTexture1;
			if (skinChoosed==2) currentSkin=cubeTexture2;
			if (mapChoosed==0) currentMap=bgTexture0; 
			if (mapChoosed==1) currentMap=bgTexture1; 
			if (mapChoosed==2) currentMap=bgTexture2; 
		}



		//* RENDERING
		// Only render 1/2 frames (game will run at 30 fps visually, to reduce lag)
		if (totalFrames % 2){
			// Clear renderer
			SDL_RenderClear(renderer);

			// Render default assets (bg, cube...)
			renderImage(renderer, currentMap, (WINDOW_WIDTH + 300 - totalFrames % 2560), defaultFloorY, 2560, 720, 0);
			renderImage(renderer, currentMap, (WINDOW_WIDTH + 300 - totalFrames % 2560 + 2560), defaultFloorY, 2560, 720, 0);
			renderImage(renderer, groundTexture, WINDOW_WIDTH+300, defaultFloorY+300, WINDOW_WIDTH+300, 300, 0);
			renderImage(renderer, groundTexture, WINDOW_WIDTH+300, 70, WINDOW_WIDTH+300, 300, 1);

			// Draw cube at the end
			renderImage(renderer, currentSkin, WINDOW_WIDTH/2, defaultFloorY, BLOCK_SIZE, BLOCK_SIZE, 0);

			// Render the icons in the menu
			renderImage(renderer, SkinIconTexture,1600,900,1600,900,0);
			renderImage(renderer, PlayIconTexture,1600,900,1600,900,0);
			renderImage(renderer, SettingsIconTexture,1600,900,1600,900,0);

			// And the selector
			if(posSelectorSquare==0) renderImage(renderer, SelectorSquare1,1600,900,1600,900,0);
			if(posSelectorSquare==1) renderImage(renderer, SelectorSquare2,1600,900,1600,900,0);
			if(posSelectorSquare==2) renderImage(renderer, SelectorSquare3,1600,900,1600,900,0);

			// Render the renderer
			SDL_RenderPresent(renderer);
		}



		//* POST PROCESS
		frameTime = SDL_GetTicks() - frameStart; // Get delay between start and finish of loop
		if (frameDelay > frameTime) { SDL_Delay(frameDelay - frameTime); } // Delay the frame if needed
		totalFrames++; // Add one to total frames
		if (totalFrames > 14000){
			totalFrames = 0; // Avoid overflow
			free(soundItem);
			soundItem = loadSound("assets/gui/default.mp3");
			playSound(soundItem);
		}
	}



	//* ENDING
	// Free sound
	freeSound(soundItem);

	// Free textures
	freeTexture(cubeTexture0);
	freeTexture(cubeTexture1);
	freeTexture(cubeTexture2);
	freeTexture(groundTexture);
	freeTexture(bgTexture0);
	freeTexture(bgTexture1);
	freeTexture(bgTexture2);
	freeTexture(PlayIconTexture) ;
	freeTexture(SkinIconTexture);
	freeTexture(SettingsIconTexture);
	freeTexture(SelectorSquare1);
	freeTexture(SelectorSquare2);
	freeTexture(SelectorSquare3);

	closeSDL(window, renderer);
}