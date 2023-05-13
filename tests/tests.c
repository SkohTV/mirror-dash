#include "tests.h"



//* Global tester, run the function to test a module
void testsRun(char testName){
	switch (testName){
		case 'core': printf("Test Core Utils : %s\n", testCore() ? "failure":"success") ; break ;
		case 'list': printf("Test Linked Lists : %s\n", testLinkedLists() ? "failure":"success") ; break ;
		case 'file': printf("Test File I/O : %s\n", testFiles() ? "failure":"success") ; break ;
		case 'first': printf("Test First Level : %s\n", testFirstLevel() ? "failure":"success") ; break ;
	}
}


//* Module Test Core Utils
//! DEPRECATED, DO NOT TEST
//? Creates a window, draw basic stuff, then closes
int testCore(){
	startSDL();
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	createWindow(&window, &renderer);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	gameLoop(renderer, "assets/maps/tuto-first");
	return EXIT_SUCCESS;
}


//* Module Test Linked Lists
//? Datastructure be like
//? Ex: {c} -> {b} -> {a}
int testLinkedLists(){
	LinkedList *LL1 = NULL;
	LLpush(&LL1, ITcreate('a', 12, 13, 14));
	LLpush(&LL1, ITcreate('b', 12, 13, 14));
	LLpush(&LL1, ITcreate('c', 12, 13, 14));
	ItemEntity **its = malloc(sizeof(ItemEntity) * 3);
	for (int i = 0; i < 3; i++){ its[i] = LLpop(&LL1); }
	printf("%d\n", its[0]->type);
	printf("%d\n", its[1]->type);
	printf("%d\n", its[2]->type);
	if (!LL1){ printf("Last elem is NULL\n"); }
	free(its[0]);
	free(its[1]);
	free(its[2]);
	free(its);
	return EXIT_SUCCESS;
}


//* Module Test File I/O
//? Creates a file in the root directory, read a file in tuto-first folder
int testFiles(){
	createFile();
	LinkedList *LL1 = readFile("assets/maps/tuto-first/map.level");
	ItemEntity **its = malloc(sizeof(ItemEntity) * 3);
	for (int i = 0; i < 3; i++){ its[i] = LLpop(&LL1); }
	printf("%d\n", its[0]->type);
	printf("%d\n", its[1]->type);
	printf("%d\n", its[2]->type);
	return EXIT_SUCCESS;
}


//* Module Test First Level
//! Might become deprecated soon
//? Basic first level, few objects implemented
int testFirstLevel(){
	startSDL();
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	createWindow(&window, &renderer);
	SDL_SetRenderDrawColor(renderer, 120, 120, 120, 255);
	SDL_RenderClear(renderer);
	gameLoop(renderer, "assets/maps/tuto-first");
	closeSDL(window, renderer);
	return EXIT_SUCCESS;
}