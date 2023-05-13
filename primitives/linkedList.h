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
 * @param item 
 */
void LLpush(LinkedList **list, ItemEntity *item);

/**
 * @brief 
 * 
 * @param list 
 * @return ItemEntity* 
 */
ItemEntity *LLpop(LinkedList **list);

/**
 * @brief 
 * 
 */
ItemEntity *ITcreate(char type, int posX, int posY, int summon);

/**
 * @brief Liberate an element of a Linked List
 * 
 * @param LL 
 */
void liberationOfSpace(LinkedList **LL);



// Close safety define
#endif