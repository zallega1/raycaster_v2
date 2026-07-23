#ifndef BULLET_H
#define BULLET_H

#include <stdbool.h>
#include "map.h"
#include "gun.h"
#include "player.h"
#include <GLFW/glfw3.h>
#include "enemy.h"

struct Bullet {
	float bX, bY;
	float speed;
	bool hitEnemy;
};
extern struct Bullet b;

void fireBullet(float deltaTime);

#endif
