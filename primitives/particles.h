// Define for safety
#ifndef PARTICLES_H
#define PARTICLES_H

// Includes & Defines
#include "_structs.h"



// Functions
/**
 * @brief Create a particle array object
 * 
 * @param list 
 * @param posX 
 * @param posY 
 */
void Ppush(ItemParticle **list, int posX, int posY);

/**
 * @brief Delete a particle array object
 * 
 * @param list 
 */
void Pdrop(ItemParticle **list);

/**
 * @brief Draw a particle object to the renderer
 * 
 * @param renderer 
 * @param list 
 */
void Pdraw(SDL_Renderer *renderer, ItemParticle **list, int *pCount);



// Close safety define
#endif