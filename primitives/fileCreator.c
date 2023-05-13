#include "fileCreator.h"


void createFile(){
	FILE *fp = fopen("map.level", "w");

	putc(square, fp);
	putw(640, fp);
	putw(180, fp);


	putc(square, fp);
	putw(500, fp);
	putw(181, fp);


	putc(square, fp);
	putw(640, fp);
	putw(240, fp);

	fclose(fp);
}


LinkedList *readFile(char *dir){
	FILE *fp = fopen(dir, "r");

	if (fp == NULL){ printf("Error: Cannot open map.level file"); }

	LinkedList *LL = NULL;

	char coolbuffer;

	// Create while loop
	while ((coolbuffer = getc(fp)) != EOF){
		ItemEntity *new = malloc(sizeof(ItemEntity));
		new->type = coolbuffer;
		new->posX = WINDOW_WIDTH+300;
		new->posY = getw(fp);
		new->summon = getw(fp);
		LLpush(&LL, new);
	}


	fclose(fp);
	return LL;
}