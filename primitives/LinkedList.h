// Define for safety
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Includes & Defines
#include "_structs.h"


// Functions
/***/
void LLnew(LinkedList *list);

/***/
ItemEntity LLpush(LinkedList *list, ItemEntity *item);

/***/
void LLpop(LinkedList *list);

/***/
//void LLapply(LinkedList *list, char (*functionVerif)(ItemEntity), void (*functionApply)(ItemEntity));
void LLapply(LinkedList *list, char mode);



// Close safety define
#endif