#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include "map.h"
#include "door.h"
#include "enemy.h"

#define PI 3.14159

struct Player {
	float pX, pY; //player x and y coordinates
	float pAng; //player angle
	float dX, dY; //delta x and delta y
	float speed; //player speed, depending on collision detection
	int health;
	int state; //0 while alive, 1 when dead
};
extern struct Player p; //create player character globally

void initPlayer(); //initialize player health, spawn, etc
void drawPlayer(); //draw player on 2D map
bool checkCollision(float x, float y); //check collision of player
void damagePlayer(); //for when player takes damage

#endif