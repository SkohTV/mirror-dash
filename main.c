// Includes from ...
#include "primitives/core.h"
#include "primitives/LinkedList.h"
#include "interfaces/mouvement.h"
#include "interfaces/gameLoop.h"


// Tests for imported modules
//int testCore();


//int main(int argc, char *argv[]){
int main(){
	//testCore();
	LinkedListTest();

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
	//setWindowFullscreen(&window);

	//loadImage(renderer, 0, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);

	gameLoop(renderer);
	
	return EXIT_SUCCESS;
}

int LinkedListTest(){
	LinkedList *LL1;
	LLnew(LL1);
	ITcreate('a', 12, 13, 14);
	LLpush(LL1, ITcreate('a', 12, 13, 14));
	printf("a\n");
	LLpush(LL1, ITcreate('b', 12, 13, 14));
	LLpush(LL1, ITcreate('c', 12, 13, 14));
	printf("%c\n", LLpop(LL1).type);
	printf("%c\n", LLpop(LL1).type);
	printf("%c\n", LLpop(LL1).type);
}