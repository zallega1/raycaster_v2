#ifndef DOOR_H
#define DOOR_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "map.h"

/* the door struct works via player collision checks.
	if the player is on a tile corresponding to a door,
	the coordinates and boolean variables will be stored
	in the struct*/
struct Door {
	GLuint doorTexture;
	bool inRange, isOpened;
	int dTileX, dTileY, type; //tile positions of door
};
extern struct Door d;

//opens the door
void openDoor(int tileX, int tileY, int type);

#endif
