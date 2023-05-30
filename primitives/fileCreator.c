#include "fileCreator.h"





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




// DO NO GO BELOW THIS POINT
// Pls, I am ashamed



//! Manual creation of level
void createFile1(){
	FILE *fp = fopen("assets/maps/first/map.level", "w");


	putc(spikeUp, fp);
	putw(790, fp);
	putw(225, fp);

	putc(spikeUp, fp);
	putw(790, fp);
	putw(440, fp);

	putc(spikeUp, fp);
	putw(790, fp);
	putw(545, fp);

	putc(spikeUp, fp);
	putw(790, fp);
	putw(655, fp);

	putc(spikeUp, fp);
	putw(790, fp);
	putw(755, fp);

	putc(spikeUp, fp);
	putw(790, fp);
	putw(855, fp);

	putc(gravityPadUp, fp);
	putw(790, fp);
	putw(1005, fp);

	putc(spikeLeft, fp);
	putw(790, fp);
	putw(1045, fp);

	putc(spikeLeft, fp);
	putw(710, fp);
	putw(1045, fp);
	
	putc(spikeLeft, fp);
	putw(630, fp);
	putw(1045, fp);

	putc(square, fp);
	putw(790, fp);
	putw(1055, fp);

	putc(square, fp);
	putw(710, fp);
	putw(1055, fp);
	
	putc(square, fp);
	putw(630, fp);
	putw(1055, fp);

	putc(spikeDown, fp);
	putw(150, fp);
	putw(1115, fp);

	putc(spikeDown, fp);
	putw(150, fp);
	putw(1215, fp);

	putc(spikeDown, fp);
	putw(150, fp);
	putw(1315, fp);

	putc(jumpCircle, fp);
	putw(260, fp);
	putw(1415, fp);

	putc(square, fp);
	putw(150, fp);
	putw(1430, fp);

	putc(spikeDown, fp);
	putw(230, fp);
	putw(1430, fp);

	putc(jumpCircle, fp);
	putw(260, fp);
	putw(1515, fp);

	putc(square, fp);
	putw(150, fp);
	putw(1530, fp);

	putc(spikeDown, fp);
	putw(230, fp);
	putw(1530, fp);

	putc(jumpCircle, fp);
	putw(260, fp);
	putw(1615, fp);

	putc(square, fp);
	putw(150, fp);
	putw(1630, fp);

	putc(spikeDown, fp);
	putw(230, fp);
	putw(1630, fp);

	putc(jumpCircle, fp);
	putw(260, fp);
	putw(1715, fp);

	putc(jumpCircle, fp);
	putw(460, fp);
	putw(1740, fp);

	putc(square, fp);
	putw(150, fp);
	putw(1740, fp);

	putc(square, fp);
	putw(230, fp);
	putw(1740, fp);

	putc(spikeDown, fp);
	putw(310, fp);
	putw(1740, fp);

	putc(endOfGame, fp);
	putw(790, fp);
	putw(1760, fp);


	fclose(fp);
}



//! Manual creation of level
void createFile2(){
	FILE *fp = fopen("assets/maps/second/map.level", "w");


	putc(jumpCircle, fp);
	putw(650, fp);
	putw(90, fp);

	putc(jumpPadUp, fp);
	putw(790, fp);
	putw(100, fp);

	putc(square, fp);
	putw(650, fp);
	putw(110, fp);

	putc(square, fp);
	putw(650, fp);
	putw(120, fp);

	putc(square, fp);
	putw(650, fp);
	putw(130, fp);

	putc(square, fp);
	putw(650, fp);
	putw(140, fp);

	putc(square, fp);
	putw(650, fp);
	putw(150, fp);

	putc(square, fp);
	putw(650, fp);
	putw(160, fp);

	putc(spikeUp, fp);
	putw(570, fp);
	putw(160, fp);

	putc(gravityPadUp, fp);
	putw(790, fp);
	putw(180, fp);

	putc(gravityCircle, fp);
	putw(370, fp);
	putw(210, fp);


	putc(endOfGame, fp);
	putw(790, fp);
	putw(1760, fp);


	fclose(fp);
}



//! Manual creation of level
void createFile3(){
	FILE *fp = fopen("assets/maps/third/map.level", "w");


	putc(spikeUp, fp);
	putw(790, fp);
	putw(225, fp);

	putc(endOfGame, fp);
	putw(790, fp);
	putw(1760, fp);


	fclose(fp);
}