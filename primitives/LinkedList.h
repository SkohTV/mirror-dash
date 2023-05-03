// Define for safety
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Includes & Defines
#include "_structs.h"


// Functions
/**
 * @brief 
 * 
 * @param list 
 */
void LLnew(LinkedList *list);

/**
 * @brief 
 * 
 * @param list 
 * @param item 
 */
void LLpush(LinkedList *list, ItemEntity *item);

/**
 * @brief 
 * 
 * @param list 
 * @return ItemEntity 
 */
ItemEntity LLpop(LinkedList *list);

/***/
//void LLapply(LinkedList *list, char (*functionVerif)(ItemEntity), void (*functionApply)(ItemEntity));
//void LLapply(LinkedList *list, char mode);

/**
 * @brief 
 * 
 */
ItemEntity *ITcreate(char type, int posX, int posY, int summon);



// Close safety define
#endif