// Define for safety
#ifndef _STRUCTS_H
#define _STRUCTS_H

//#define WINDOW_WIDTH 640
//#define WINDOW_HEIGHT 480

#define WINDOW_WIDTH 640*2
#define WINDOW_HEIGHT 480*2

#define JUMP_FORCE 25.0


// Global Includes
// Those will be imported on almost all .h
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Structs & Enums
// A small paragraph of comment describe their use

//* Enum shapes
// Contain all shapes that can be drawn on canva
typedef enum _Shape{
	cube = 0,
	background = 1,
} Shape;



// Close safety define
#endif