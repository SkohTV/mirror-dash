#include "fileCreator.h"



//! WILL BE DEPRECATED SOON
void createFile(){
	FILE *fp = fopen("map.level", "w");

	// Obj 1
	putc(square, fp);
	putw(640, fp);
	putw(180, fp);

	// Obj 2
	putc(square, fp);
	putw(450, fp);
	putw(360, fp);

	// Obj 3
	putc(spikeUp, fp);
	putw(640, fp);
	putw(540, fp);

	fclose(fp);
}

//! REMINDER : Files are written in a custom format
//? Here is the said format :
// char type -> 1 int posY -> 1 int summon
// And then start again
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