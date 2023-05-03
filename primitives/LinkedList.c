#include "LinkedList.h"



void LLnew(LinkedList *list){
	list = malloc(sizeof(LinkedList));
	list->item = NULL;
	list->next = NULL;
}


void LLpush(LinkedList *list, ItemEntity *item){
	if (list->next == NULL){
		LinkedList *new = malloc(sizeof(LinkedList));
		new->item = item;
		new->next = NULL;
		} else { printf("Err\n"); }
	//} else { LLpush(list->next, item); }
}


ItemEntity LLpop(LinkedList *list){
	// Free ItemEntity
	free(list->item);
	// Free LinkedList
	free(list);
}


//void LLapply(LinkedList *list, char mode){
	
//}

ItemEntity *ITcreate(char type, int posX, int posY, int summon){
	ItemEntity *new = malloc(sizeof(ItemEntity));
	new->type = type;
	new->posX = posX;
	new->posY = posY;
	new->summon = summon;
	return new;
}