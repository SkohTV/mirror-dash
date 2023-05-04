#include "linkedList.h"



LinkedList *LLnew(){
	LinkedList *new = NULL;
	return new;
}


void LLpush(LinkedList **list, ItemEntity *item){
	if (*list == NULL){
		LinkedList *new = malloc(sizeof(LinkedList));
		new->item = item;
		new->next = *list;
		*list = new;
	} else { LLpush(&((*list)->next), item); } // We need to go back as a pointer ** (so use of &)
}


//! Doesn't free the item !!
ItemEntity *LLpop(LinkedList **list){
	LinkedList *tmpList = *list;
	ItemEntity *tmpItem = (*list)->item;
	*list = (*list)->next;
	free(tmpList);
	return tmpItem;
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