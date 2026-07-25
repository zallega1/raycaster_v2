#ifndef DOOR_H
#define DOOR_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "map.h"

#define MAX_DOORS 20

/* the door struct works via player collision checks.
	if the player is on a tile corresponding to a door,
	the coordinates and boolean variables will be stored
	in the struct*/
struct Door {
	GLuint doorTexture;
	bool inRange, isOpened;
	int dTileX, dTileY, type; //tile positions of door
};
struct Door d[MAX_DOORS];

GLuint doorTex;
int numberOfDoors;

//creates a door object with coordinates and tag number
//type can be 2 (vertically aligned) or 3 (horizontally aligned)
void createDoor(int doorTileX, int doorTileY, int num, int type);

//initializes doors and door coordinates
void initDoors(); 

//opens the door
void openDoor(int num);

#endif
