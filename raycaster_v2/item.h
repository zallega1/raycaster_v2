#ifndef ITEM_H
#define ITEM_H

#include <stdbool.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include "imageloader.h"
#include "player.h"
#include "map.h"
#include "gun.h"

struct Item {
	bool rendered, pickedUp; 
	GLuint itemTexture;
	float iX, iY, distToPlayer;
	int itemType, index;
	float itemX1, itemX2, itemY1, itemY2; //for raycasting
};
extern struct Item it[30];
extern int numberOfItems;

//initializes the items for each level
void initItems();

//creates the item and sets spawn coordinates
void createItem(float itemX, float itemY, int itemType, int num);

//draw the item on the 2d map
void drawItem(int num);

//check if player walked over item
void pickupItem(int num);

//logic for medkit item
void healPlayer(int num);

//logic for ammo refill item
void refillAmmo(int num);

#endif