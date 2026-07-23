#ifndef DRAW_H
#define DRAW_H

#include <GLFW/glfw3.h>
#include "imageloader.h"
#include <string.h>

#define SCREEN_WIDTH 1600

//for drawing rectangles
void drawRect(int x1, int x2, int y1, int y2);

//for drawing textured rectangles
void drawTexRect(GLuint tex, float texCoordx1, float texCoordx2, float texCoordy1, float texCoordy2, int x1, int x2, int y1, int y2);

//for writing text to screen
void drawText(char text[], int x1, int x2, int y1, int y2);

#endif
