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
 * @param skin
 * @return int 
 */
int gameLoop(SDL_Renderer *renderer, char *mapDir, char skin);

/**
 * @brief Function that starts a game, and wrap it
 * 
 * @param renderer 
 * @param mapDir 
 * @param skin
 * @return int 
 */
int gameInterface(SDL_Renderer *renderer, char *mapDir, char skin);


// Close safety define
#endif