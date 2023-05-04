#include "fileCreator.h"



void createFile(){
	FILE *fp = fopen("map.level", "w");

	putc(3, fp);
	putw(300, fp);
	putw(180, fp);


	putc(6, fp);
	putw(500, fp);
	putw(181, fp);


	putc(9, fp);
	putw(9999, fp);
	putw(3600, fp);

	fclose(fp);
}


LinkedList *readFile(){
	FILE *fp = fopen("map.level", "r");
	LinkedList *LL = LLnew();

	char coolbuffer;

	// Create while loop
	while ((coolbuffer = getc(fp)) != EOF){
		ItemEntity *new = malloc(sizeof(ItemEntity));
		new->type = coolbuffer;
		new->posX = NULL;
		new->posY = getw(fp);
		new->summon = getw(fp);
		LLpush(&LL, new);
	}


	fclose(fp);
	return LL;
}