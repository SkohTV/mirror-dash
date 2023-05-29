// Define for safety
#ifndef CORE_H
#define CORE_H

// Includes & Defines
#include "_structs.h"


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
 * @brief Render an image to renderer from a texture, and coordinates
 * 
 * @param renderer 
 * @param texture 
 * @param X 
 * @param Y 
 * @param W 
 * @param H 
 */
void renderImage(SDL_Renderer *renderer ,SDL_Texture *texture, int X, int Y, int W, int H, char flip);

/**
 * @brief 
 * 
 * @param texture 
 */
void freeTexture(SDL_Texture *texture);

/**
 * @brief Init the sound engine
 * 
 */
int initSound();

/**
 * @brief Load the sound from a file and play it
 * 
 * @return int 
 */
Mix_Music *loadSound(char *path);

/**
 * @brief Play the sound object
 * 
 * @param music 
 * @return int 
 */
int playSound(Mix_Music *music);

/**
 * @brief Free the sound object
 * 
 * @param music 
 * @return int 
 */
int freeSound(Mix_Music *music);

/**
 * @brief Increase the volume
 * 
 * @param volume 
 * @return int 
 */
int volumeUp(int *volume);

/**
 * @brief Decrease the volume
 * 
 * @param volume 
 * @return int 
 */
int volumeDown(int *volume);



#endif