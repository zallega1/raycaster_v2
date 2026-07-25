#include "player.h"

struct Player p;

void initPlayer() {
	p.pAng = -PI / 2;
	p.pX = 50;
	p.pY = 50;
	p.health = 100;
	p.state = 0;
	p.dX = cos(p.pAng);
	p.dY = sin(p.pAng);
}

void drawPlayer() {
	//commented out code is for debugging
	//glColor3f(1, 1, 0); //draw Player on minimap
	//glPointSize(4);
	//glBegin(GL_POINTS);
	//glVertex2i(p.pX, p.pY);
	//glEnd();

	p.dX = cos(p.pAng);
	p.dY = sin(p.pAng);

	/*glPointSize(1);
	glBegin(GL_LINES);
	glVertex2i(p.pX, p.pY);
	glVertex2i(p.pX + p.dX * 7.5, p.pY + p.dY * 7.5);
	glEnd();*/
}

bool checkCollision(float x, float y) {
	int collX, collY;
	collX = (int)(x / cellSize);
	collY = (int)(y / cellSize);
	//collision checking for walls
	if (map[collY][collX] != 0) {
		if (map[collY][collX] == 1) {
			return true; //collision detected
		}
		else if (map[collY][collX] == 2) { //verically aligned door
			int x1 = collX * cellSize;
			int x2 = x1 + cellSize;
			int xC = (x1 + x2) / 2;
			if (x >= xC - 2 && x <= xC + 2) {
				return true;
			}
		}
		else if (map[collY][collX] == 3) { //horizontally aligned door
			int y1 = collY * cellSize;
			int y2 = y1 + cellSize;
			int yC = (y1 + y2) / 2;
			if (y >= yC - 2 && y <= yC + 2) {
				return true;
			}
		}
		else if (map[collY][collX] == 4) {
			p.state = 2; //player beats level when they touch end block
			return true;
		}
	}

	//check if door is in range after checking collision
	for (int i = 0; i < numberOfDoors; i++) { 
		if (d[i].dTileX == collX && d[i].dTileY == collY) {
			d[i].inRange = true;
		}
		else {
			d[i].inRange = false;
		}
	}
	//collison checking for enemies
	for (int i = 0; i < numberOfEnemies; i++) {
		if (x <= e[i].eX + 6 && x >= e[i].eX - 6) {
			if (y <= e[i].eY + 6 && y >= e[i].eY - 6) {
				if (e[i].enemyState != 3) {
					return true;
				}
			}
		}
	}
	return false;
}

void damagePlayer(int enemyType) {
	int damage; //damage depends on enemy type, with random multiplier

	switch (enemyType) {
	case 0:
	case 1:
		damage = 15 * ((rand() % 3 - 1 + 1) + 1);
		break;
	case 2:
		//will finish later
		break;
	}

	p.health -= damage;
	if (p.health <= 0) {
		p.health = 0;
		p.state = 1; //player dead state
	}
}