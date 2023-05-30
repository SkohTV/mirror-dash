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
 * @brief Create a File1 object
 * 
 */
void createFile1();

/**
 * @brief Create a File2 object
 * 
 */
void createFile2();

/**
 * @brief Create a File3 object
 * 
 */
void createFile3();





// Close safety define
#endif