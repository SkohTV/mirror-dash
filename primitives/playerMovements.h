// Define for safety
#ifndef PLAYERMOVEMENTS_H
#define PLAYERMOVEMENTS_H

// Includes & Defines
#include "_structs.h"


// Functions
/**
 * @brief Return the plus or minus to the X position of the cube (with return)
 * 
 * @param accelerate 
 * @return int 
 */
int jumpTrajectory(int *accelerate, char gravity);

/**
 * @brief Return the plus or minus to the Y position of the cube (in place)
 * 
 * @param accelerate 
 * @param gravity 
 */
void playerJump(int *accelerate, char gravity);

//! OTHERS PARAMS TO PASS INTO
/**
 * @brief Return the plus or minus to the Y position of the cube
 * 
 * @param gravity 
 * @param floorY 
 * @param accelerate 
 * @param grounded
 */
void reverseGravity(char *gravity, int *floorY, int *accelerate, char *grounded);



// Close safety define
#endif