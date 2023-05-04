// Define for safety
#ifndef TESTS_H
#define TESTS_H

// Includes & Defines
#include "../primitives/_structs.h"

#include "../primitives/core.h"
#include "../primitives/linkedList.h"
#include "../primitives/fileCreator.h"

#include "../interfaces/mouvement.h"
#include "../interfaces/gameLoop.h"

// Functions
/**
 * @brief 
 * 
 */
void testsRun();

/**
 * @brief 
 * 
 * @return int 
 */
int testCore();

/**
 * @brief 
 * 
 * @return int 
 */
int testLinkedLists();

/**
 * @brief 
 * 
 * @return int 
 */
int testFiles();


// Close safety define
#endif