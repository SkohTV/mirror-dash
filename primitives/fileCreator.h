// Define for safety
#ifndef FILECREATOR_H
#define FILECREATOR_H

// Includes & Defines
#include "_structs.h"

#include "../primitives/linkedList.h"
#include "core.h"



// Functions
/**
 * @brief Read a map file and return a future object Linked List (LL1)
 * 
 * @param dir 
 * @return LinkedList* 
 */
LinkedList *readFile(char *dir);

/**
 * @brief Build first level
 * 
 */
void createFile1();

/**
 * @brief Build second level
 * 
 */
void createFile2();

/**
 * @brief Build third level
 * 
 */
void createFile3();





// Close safety define
#endif