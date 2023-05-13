// Define for safety
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Includes & Defines
#include "_structs.h"



// Functions
/**
 * @brief Push an item to the Linked List (at start)
 * 
 * @param list 
 * @param item 
 */
void LLpush(LinkedList **list, ItemEntity *item);

/**
 * @brief Pop an item from the Linked List and returns is (at end)
 * 
 * @param list 
 * @return ItemEntity* 
 */
ItemEntity *LLpop(LinkedList **list);

/**
 * @brief Create an object ItemEntity and returns it
 * 
 * @param type 
 * @param posX 
 * @param posY 
 * @param summon 
 * @return ItemEntity* 
 */
ItemEntity *ITcreate(char type, int posX, int posY, int summon);

/**
 * @brief Handle logic, liberation and freeing of LL2 in gameloop
 * 
 * @param LL 
 */
void liberationOfSpace(LinkedList **LL);



// Close safety define
#endif