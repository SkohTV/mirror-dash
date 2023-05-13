// Define for safety
#ifndef GAMELOOP_H
#define GAMELOOP_H

// Includes & Defines
#include "../primitives/_structs.h"
#include "../primitives/linkedList.h"


// Functions
/**
 * @brief Loop each tick, do actions
 * 
 * @param renderer 
 * @param mapDir
 */
void gameLoop(SDL_Renderer *renderer, char *mapDir);



// Close safety define
#endif