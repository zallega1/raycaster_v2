#ifndef RAYCASTER_H
#define RAYCASTER_H

#include <GLFW/glfw3.h>
#include <math.h>
#include "map.h"
#include "player.h"
#include "draw.h"
#include "wall.h"
#include "door.h"
#include "enemy.h"
#include "item.h"

#define PI 3.14159
#define SCREEN_WIDTH 1600

struct Rays {
	//ray positins, angle, DX and DY are cos and sin
	float rayX1, rayX2, rayY1, rayY2, rayAngle, rayDX, rayDY;
	int numRays;
};
struct Rays r;

//cast the drawn rays on screen to create a 3D environment
void castRays(int i);

//draw the rays on the 2D map from the player to the walls 
void drawRays();

//function that determines current enemy sprite
void enemyTexture(int i);

//cast the enemy sprite on to the 3d environment
void castEnemies();

//cast the item sprite on to the 3d enviornment
void castItems();

#endif