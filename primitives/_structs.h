// Define for safety
#ifndef _STRUCTS_H
#define _STRUCTS_H


#define WINDOW_WIDTH 1280 //! DEPRECATED, BUT STILL USED
#define WINDOW_HEIGHT 720 //! DEPRECATED, BUT STILL USED
#define BLOCK_SIZE 80 // Size of a block, all blocks are same size, player included
#define LOW_BLOCK_SIZE 60 // Size of pads
#define SAFETY_MARGIN 20 // Safety margin for player when collision

#define JUMP_FORCE 20 // Strength of jump of player
#define CAPPED_FPS 60 // Max ticks, real max fps is half of it (so 30)


// Global Includes
// Those will be imported on almost all .h
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>


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
	gravityPadUp = 8,
	gravityPadDown = 9,
	gravityCircle = 10,
	jumpPadUp = 11,
	jumpPadDown = 12,
	jumpCircle = 13,
	endOfGame = 70,
	SelectorSkinIcon = 94,
	SelectorSettingsIcon = 95,
	SelectorPlayIcon = 96,
	skinIcon = 97,
	settingsIcon = 98,
	playIcon = 99,
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
// Make the use of many ItemEntity easier and way faster
typedef struct _LinkedList{
	struct _ItemEntity *item;
	struct _LinkedList *next;
} LinkedList;


//* Particle Linked List
// Store all particles for the player
typedef struct _ItemParticle{
	int posX;
	int posY;
	struct _ItemParticle *next;
} ItemParticle;


// Close safety define
#endif