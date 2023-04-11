// Define for safety
#ifndef CORE_H
#define CORE_H

// Includes & Defines
#include "_structs.h"
#include "../interfaces/mouvement.h"


// Functions
/**
 * @brief Start the SDL client, exit program if error
 * 
 */
void startSDL();

/**
 * @brief Close the SDL (don't free)
 * 
 * @return int 
 */

int closeSDL();

/**
 * @brief Create a Window object
 * 
 * @param window 
 * @param renderer 
 * @return int 
 */
int createWindow(SDL_Window **window, SDL_Renderer **renderer);

/**
 * @brief Free the window object
 * 
 * @param window 
 * @param renderer 
 * @return int 
 */
int freeWindow(SDL_Window *window, SDL_Renderer *renderer);

/**
 * @brief Load an image from a file, at coordinates
 * 
 * @param renderer 
 * @param shape 
 * @param X 
 * @param Y 
 */
void loadImage(SDL_Renderer *renderer, char shape, int X, int Y);

/**
 * @brief Handle any key press nor click
 * 
 * @param renderer 
 */
void eventHandler(SDL_Renderer *renderer);

/**
 * @brief Return the plus or minus to the X position of the cube
 * 
 * @param accelerate 
 * @return int 
 */
int jumpTrajectory(float *accelerate);



// Close safety define
#endif