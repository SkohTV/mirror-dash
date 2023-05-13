// Define for safety
#ifndef FILECREATOR_H
#define FILECREATOR_H

// Includes & Defines
#include "_structs.h"

#include "../primitives/linkedList.h"
#include "core.h"



// Functions
/**
 * @brief Create a file with predefined configs for a map
 * 
 */
void createFile();

/**
 * @brief Read a map file and return a future object Linked List (LL1)
 * 
 * @param dir 
 * @return LinkedList* 
 */
LinkedList *readFile(char *dir);




// Close safety define
#endif