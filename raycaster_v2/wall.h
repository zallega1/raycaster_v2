#ifndef WALL_H
#define WALL_H

#include <GLFW/glfw3.h>
#include "imageloader.h"

struct Wall {
	float wallX1, wallX2, wallY1, wallY2;
	GLuint wallTexture, exitTexture;
	float texX1, texX2, texY1, texY2; //for texture mapping
};
struct Wall w;

#endif
