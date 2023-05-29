#include "fileCreator.h"



//! WILL BE DEPRECATED SOON
void createFile(){
	FILE *fp = fopen("map.level", "w");

	// Obj 4
	putc(gravityPadUp, fp);
	putw(790, fp);
	putw(180, fp);

	// Obj 5
	putc(gravityCircle, fp);
	putw(340, fp);
	putw(200, fp);

	// Obj 8
	putc(spikeUp, fp);
	putw(790, fp);
	putw(360, fp);

	// Obj 9
	putc(square, fp);
	putw(790, fp);
	putw(440, fp);

	// Obj 10
	putc(square, fp);
	putw(790, fp);
	putw(480, fp);

	// Obj 6
	putc(jumpPadUp, fp);
	putw(790, fp);
	putw(540, fp);

	// Obj 7
	putc(jumpCircle, fp);
	putw(540, fp);
	putw(560, fp);

	// Obj 7
	putc(jumpCircle, fp);
	putw(540, fp);
	putw(560, fp);

	// End
	putc(endOfGame, fp);
	putw(790, fp);
	putw(600, fp);

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