// Define for safety
#ifndef _STRUCTS_H
#define _STRUCTS_H


#define WINDOW_WIDTH 1280 //! DEPRECATED, BUT STILL USED
#define WINDOW_HEIGHT 720 //! DEPRECATED, BUT STILL USED
#define BLOCK_SIZE 80 // Size of a block, all blocks are same size, player included
#define SAFETY_MARGIN 20 // Safety margin for player when collision

#define JUMP_FORCE 20 // Strength of jump of player

#define CAPPED_FPS 60 // Max ticks, real max fps is half (so 30)


// Global Includes
// Those will be imported on almost all .h
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


// Structs & Enums
// A small paragraph of comment describe their use

//* Enum shapes
// Contain all shapes that can be drawn on renderer
typedef enum _Shape{
	cube = 0,
	background = 1,
	ground = 2,
	square = 3,
	spikeUp = 4,
	spikeDown = 5,
	spikeLeft = 6,
	spikeRight = 7,
	gravityPad = 8,
	gravityCircle = 9,
	jumpPad = 10,
	jumpCircle = 11
} Shape;


//* Item Node
// Stored in Linked List, contain all data for an item to be drawn/managed
typedef struct _ItemEntity{
	char type;
	int posX;
	int posY;
	int summon;
	SDL_Texture *texture;
} ItemEntity;


//* Linked List
// Make ithe use of many ItemEntity easier and way faster
typedef struct _LinkedList{
	struct _ItemEntity *item;
	struct _LinkedList *next;
} LinkedList;


// Close safety define
#endif