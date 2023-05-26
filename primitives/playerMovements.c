#include "playerMovements.h"



//? We don't need to much of a complexe script, since it's just vertical jump
int jumpTrajectory(int *accelerate, char gravity){
	(*accelerate) = (*accelerate) - gravity;
	return (*accelerate);
}


void playerJump(int *accelerate, char gravity){
	(*accelerate) = JUMP_FORCE * gravity;
}


void reverseGravity(char *gravity, int *floorY, int *accelerate, char *grounded){
	(*gravity) = ((*gravity) * (-1));
	(*accelerate) = (*gravity) * 2;
	(*grounded) = 0;
	
	if ((*gravity) == 1){ (*floorY) = 8*(WINDOW_HEIGHT/9)+150; }
	else { (*floorY) = 150; }
}