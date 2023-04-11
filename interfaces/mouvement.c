#include "mouvement.h"


// Complexity : O( )
//
void jump(SDL_Renderer *renderer){

	// Todo /   Code here
	int start = 100;
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = WINDOW_HEIGHT/2;
	
	while (XPosition > 0){
		loadImage(renderer, 0, XPosition, YPosition);
		YPosition = YPosition - jumpTrajectory(&start);
		if(YPosition < WINDOW_HEIGHT/2){
			break;
		}
	}
}
