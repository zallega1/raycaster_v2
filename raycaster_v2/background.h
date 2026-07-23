#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <GLFW/glfw3.h>
#include "draw.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200

//draws the background of the title screen/main menu
void drawTitleBackground(int select);

//draws the background of the level select screen
void drawLevelSelectBackground(int select);

//draws the background of the level complete screen
void drawLevelCompleteBackground(int screen);

//draws the background of the level
void drawLevelBackground(int level);

#endif