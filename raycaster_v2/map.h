#ifndef MAP_H
#define MAP_H

#include <GLFW/glfw3.h>

//cellSize is used by multiple different functions when doing calculations
extern int cellSize;

//level keeps track of the current level
extern int level;

//2D array for map, fixed size for now
extern int map[32][32];

//initialize the level
void initMap();

//draws the 2D top-down map where the game actually takes place
void drawMap();

#endif
