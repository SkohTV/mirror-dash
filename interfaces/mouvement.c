#include "mouvement.h"


// Complexity : O( )
//
void playerJump(){
	double start = 100.0;
	int XPosition = WINDOW_WIDTH/2;
	int YPosition = WINDOW_HEIGHT/2;
	
	while (XPosition > 0){
		YPosition = YPosition - jumpTrajectory(&start);
		if(YPosition < WINDOW_HEIGHT/2){
			break;
		}
	}
}
