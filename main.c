// Includes from ...
#include "primitives/core.h"
#include "interfaces/mouvement.h"
#include "interfaces/gameLoop.h"


// Tests for imported modules
int testCore();


//int main(int argc, char *argv[]){
int main(){
	testCore();

	// Todo /   Other module tests

	return EXIT_SUCCESS;
}


//* Module 1
// Datastructure be like
// Ex: 1 -> 6 -> 3 -> 8 (to visualize while coding)
int testCore(){
	startSDL();
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	createWindow(&window, &renderer);
	setWindowFullscreen(&window);

	loadImage(renderer, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

	eventHandler(renderer);
	
	return EXIT_SUCCESS;
}