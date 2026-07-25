#ifndef ENEMY_H
#define ENEMY_H

#include <stdbool.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include "imageloader.h"
#include "player.h"
#include "bullet.h"
#include "map.h"

#define PI 3.14159

#define ENEMY_ARR_SIZE 3

struct Enemy {
	float time; //variable for deltaTime
	float eX, eY, edX, edY;
	int enemyState; //0 for waiting, 1 for active, 2 for shooting, 3 for dead
	int enemyHealth; //when 0, is dead
	int enemyType; //what kind of enemy is it?
	int index; //gets ray that hits the enemy for positioning on screen
	float distToPlayer, enemyAngle; //used for enemy movement
	GLuint currentTex; //current enemy texture being displayed on screen
	float enemyX1, enemyX2, enemyY1, enemyY2; //for raycasting
	float angleFacingPlayer; //determines which sprite is loaded in
	bool rendered; //is enemy rendered on screen?
	float enemySpeed; //enemy movement speed
	int posToTileX, posToTileY, posToTileX2, posToTileY2; //for finding position of ray endpoint on gridmap
	float rayX1, rayX2, rayY1, rayY2, rayDX, rayDY, rayAngle; //for finding path to player
	float rayX3, rayX4, rayY3, rayY4, rayDX2, rayDY2, rayAngle2; //for finding player between two lines
	bool isFiring; //is enemy shooting?
	float eBX, eBY; //bullet x and y coordinates
	bool hitPlayer; //did enemy bullet hit player?
};
struct Enemy e[10];

struct EnemyTex {
	GLuint enemyTexFront, enemyTexBack, enemyTexLeft, enemyTexRight;
	GLuint enemyShoot1, enemyShoot2, enemyWalk1, enemyWalk2, enemyWalk3, enemyWalk4;
	GLuint enemyDead1, enemyDead2, enemyDead3, enemyDead4;
};
struct EnemyTex eTex[3];

int numberOfEnemies;


//initialize the enemy for each level
void initEnemies();

//creates the enemy and sets spawn coordinates
//coordinates are always int values when initialized but are float for calculation purposes
void createEnemy(float enemyX, float enemyY, int type, int num, float angle);

//draw the enemy on the 2D top down map
void drawEnemy(int num, float deltaTime);

//function that controls enemy states
void enemyAI(int num);

//function that creates enemy FOV to look for player
void lookForPlayer(int num);

//animates sprite while walking
void animateWalk(int num);

//start following player, with RNG chance to shoot
void trackPlayer(int num);

//checks enemy collision with player and walls
bool enemyCheckCollision(int num);

//enemy shooting function
void enemyShoot(int num);

//animates sprite when enemy dies
void animateDeath(int num);

//for when enemy takes damage
void enemyTakeDamage(int num, int playerWeapon);

//function that loads enemy textures on level initialization
void loadEnemyTex(int num);

#endif
