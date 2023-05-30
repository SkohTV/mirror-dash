#include "linkedList.h"


//? We are creating a QUEUE, so we push at end and pop at start
//? A new list is always just NULL
void LLpush(LinkedList **list, ItemEntity *item){
	if (*list == NULL){
		LinkedList *new = malloc(sizeof(LinkedList));
		new->item = item;
		new->next = *list;
		*list = new;
	} else { LLpush(&((*list)->next), item); } // We need to go back as a pointer ** (so use of &)
}


//! Doesn't free the item !! (intentionally)
ItemEntity *LLpop(LinkedList **list){
	LinkedList *tmpList = *list; // Save Linked List for free later
	ItemEntity *tmpItem = (*list)->item; // Save item for return value
	*list = (*list)->next;
	free(tmpList);
	return tmpItem;
}


ItemEntity *ITcreate(char type, int posX, int posY, int summon){
	ItemEntity *new = malloc(sizeof(ItemEntity));
	new->type = type;
	new->posX = posX;
	new->posY = posY;
	new->summon = summon;
	new->texture = NULL; // We don't init texture first
	return new;
}


// Check gameloop for its use
void liberationOfSpace(LinkedList **LL){
	if (*LL) { // if LL exists
		liberationOfSpace(&((*LL)->next)); // Go deeper in object
		if ((*LL)->item->posX < -BLOCK_SIZE){ // If item out of bound
			ItemEntity *tmp = LLpop(LL);
			free(tmp);
		}
	}
}