#ifndef MAP_H
#define MAP_H

#include <GLFW/glfw3.h>
#include "door.h"

#define X_TILES 32
#define Y_TILES 32

//cellSize is used by multiple different functions when doing calculations
int cellSize;

//level keeps track of the current level
int level;

//2D array for map, fixed size for now
int map[Y_TILES][X_TILES];

//initialize the level
void initMap();

//draws the 2D top-down map where the game actually takes place
void drawMap();

#endif
