#include "tests.h"


//*
void testsRun(){
	//printf("Test Core Utils : %s\n", testCore() ? "failure":"success");
	//printf("Test Linked Lists : %s\n", testLinkedLists() ? "failure":"success");
	//printf("Test File I/O : %s\n", testFiles() ? "failure":"success");
	printf("Test First Level : %s\n", testFirstLevel() ? "failure":"success");
}


//* Module Test Core Utils
// Datastructure be like
// Ex: 1 -> 6 -> 3 -> 8 (to visualize while coding)
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
// Datastructure be like
// Ex: 1 -> 6 -> 3 -> 8 (to visualize while coding)
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


int testFiles(){
	//createFile();
	LinkedList *LL1 = readFile("assets/maps/tuto-first/map.level");
	ItemEntity **its = malloc(sizeof(ItemEntity) * 3);
	for (int i = 0; i < 3; i++){ its[i] = LLpop(&LL1); }
	printf("%d\n", its[0]->type);
	printf("%d\n", its[1]->type);
	printf("%d\n", its[2]->type);
	return EXIT_SUCCESS;
}


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