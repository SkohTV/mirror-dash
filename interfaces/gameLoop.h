// Define for safety
#ifndef GAMELOOP_H
#define GAMELOOP_H

// Includes & Defines
#include "../primitives/_structs.h"
#include "../primitives/linkedList.h"


// Functions
/**
 * @brief Main game function, alive while the game is
 * 
 * @param renderer 
 * @param mapDir
 * @return int 
 */
int gameLoop(SDL_Renderer *renderer, char *mapDir);

/**
 * @brief Function that starts a game, and wrap it
 * 
 * @param renderer 
 * @param mapDir 
 * @return int 
 */
int gameInterface(SDL_Renderer *renderer, char *mapDir);


// Close safety define
#endif