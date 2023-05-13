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
 * @brief Close the SDL and free
 * 
 * @param window 
 * @param renderer 
 * @return int 
 */
int closeSDL(SDL_Window *window, SDL_Renderer *renderer);

/**
 * @brief Create a Window object
 * 
 * @param window 
 * @param renderer 
 * @return int 
 */
int createWindow(SDL_Window **window, SDL_Renderer **renderer);

/**
 * @brief Load an image from a file, at coordinates
 * 
 * @param renderer 
 * @param shape 
 * @return SDL_Texture* 
 */
SDL_Texture *loadImage(SDL_Renderer *renderer, char shape);

/**
 * @brief 
 * 
 * @param renderer 
 * @param texture 
 * @param X 
 * @param Y 
 * @param W 
 * @param H 
 */
void renderImage(SDL_Renderer *renderer ,SDL_Texture *texture, int X, int Y, int W, int H);

/**
 * @brief Return the plus or minus to the X position of the cube
 * 
 * @param accelerate 
 * @return double 
 */
int jumpTrajectory(double *accelerate);



// Close safety define
#endif