#include "bullet.h"

struct Bullet b;

void fireBullet(float deltaTime) {
	if (g.weapon == 1) {
		b.speed = 5 * deltaTime;
	}
	b.hitEnemy = false;
	int bxToMap = (int)(b.bX) / cellSize;
	int byToMap = (int)(b.bY) / cellSize;
	while (map[byToMap][bxToMap] == 0  && b.hitEnemy == false) {
		//draw path for debug purposes
		/*glColor3f(0, 1, 0);
		glPointSize(4);
		glBegin(GL_POINTS);
		glVertex2i(b.bX, b.bY);
		glEnd();*/

		b.bX += p.dX * b.speed;
		bxToMap = (int)(b.bX) / cellSize;
		//printf("Bullet X position: %f\n", b.bX);
		b.bY += p.dY * b.speed;
		byToMap = (int)(b.bY) / cellSize;
		//printf("Bullet Y position: %f\n", b.bY);
		
		for (int i = 0; i < numberOfEnemies; i++) {
			//this checks if an enemy is hit, if so, it loses health
			//and switched to the "active" state
			if (b.bX <= e[i].eX + 2 && b.bX >= e[i].eX - 2) {
				if (b.bY >= e[i].eY - 2 && b.bY <= e[i].eY + 2) {
					//printf("enemy hit\n");
					enemyTakeDamage(i);
				}
			}
		}
	}
}