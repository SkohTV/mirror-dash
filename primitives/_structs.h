// Define for safety
#ifndef _STRUCTS_H
#define _STRUCTS_H


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define BLOCK_SIZE 80

#define JUMP_FORCE 20

#define CAPPED_FPS 60


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
	square = 2,
	spike = 3,
} Shape;


//* Item
typedef struct _ItemEntity{
	char type;
	int posX;
	int posY;
	int summon;
	SDL_Texture *texture;
} ItemEntity;


//* Linked List 
typedef struct _LinkedList{
	struct _ItemEntity *item;
	struct _LinkedList *next;
} LinkedList;


// Close safety define
#endif