#ifndef GUN_H
#define GUN_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include <stdio.h>
#include "imageloader.h"
#include "draw.h"
#include <math.h>
#include "keys.h"
#include "bullet.h"
#include "player.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200

#define GUN_ARR_SIZE 3

struct Gun {
	int gunX, gunY, gunW, gunH, gunXOffset, gunYOffset; //x and y coordinates of weapon on screen, also width and height of image
	GLuint currentTex;
	int weapon, ammo1; //integer corresponds to type of weapon, also ammo count
	bool isFired; //boolean determining whether gun is being fired
};
struct Gun g;

struct GunTex {
	GLuint gunTexture, gunTexture2, gunTexture3;
};
struct GunTex gTex[GUN_ARR_SIZE];

//initialize the weapon
void initWeapon();

//draws the corresponding gun on screen
void drawWeapon(int num);
 
//sawy the gun while walking
void sway();

//fires the weapon
void fireGun(float deltaTime);

//function that loads gun textures on level initialization
void loadGunTex(int num);

#endif
