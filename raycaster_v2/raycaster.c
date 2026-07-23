#include "raycaster.h"

struct Rays r;

int posToTileX, posToTileY;
int side;

void castItems(float dist) {
	//cast items
	for (int k = 0; k < numberOfItems; k++) {
		if (it[k].pickedUp == false && it[k].distToPlayer < dist && it[k].index != -100) {
			glColor3f(1, 1, 1);
			it[k].itemY1 = SCREEN_HEIGHT / 2;
			it[k].itemY2 = it[k].itemY1 + ((SCREEN_HEIGHT / it[k].distToPlayer) * 4);
			if (it[k].itemX2 - it[k].itemX1 < (SCREEN_WIDTH / it[k].distToPlayer) * 2) { //for increasing width of sprite as player gets closer
				it[k].itemX2 += (SCREEN_WIDTH / r.numRays) * 4;
			}
			if (it[k].itemX2 - it[k].itemX1 >= (SCREEN_WIDTH / it[k].distToPlayer) * 2) {
				drawTexRect(it[k].itemTexture, 0, 1, 0, 1, it[k].itemX1, it[k].itemX2, it[k].itemY1, it[k].itemY2);
			}
		}
	}
}

void castEnemies(float dist) {
	//cast enemies
	for (int i = 0; i < numberOfEnemies; i++) {
		if (e[i].distToPlayer < dist && e[i].index != -100) { //check if ray is hitting enemy for each ray cast
			glColor3f(1, 1, 1);
			e[i].enemyY1 = SCREEN_HEIGHT / 4;
			e[i].enemyY2 = e[i].enemyY1 + ((SCREEN_HEIGHT / e[i].distToPlayer) * 16);
			if (e[i].enemyX2 - e[i].enemyX1 < (SCREEN_WIDTH / e[i].distToPlayer) * 4) { //for increasing width of sprite as player gets closer
				e[i].enemyX2 += (SCREEN_WIDTH / r.numRays) * 4;
			}
			//this is legitimately some of the worst code I have ever written
			//so basically because I don't understand how to map shit from a 2d to 3d enviornment
			//i had it calculate the x2 of the enemy by incrementing it for every slice, then
			//preforming a check to see if it exceeds the desired width
			//it kind of works???
			if (e[i].enemyX2 - e[i].enemyX1 >= (SCREEN_WIDTH / e[i].distToPlayer) * 4) {
				if (e[i].enemyHealth > 0) {
					//make angle positive so my head doesn't explode
					float correctAngle = fabs(e[i].angleFacingPlayer);

					//for debugging
					//printf("%f\n", correctAngle);

					if (correctAngle < 7 * PI / 4 && correctAngle >= 5 * PI / 4) {
						drawTexRect(e[i].enemyTexBack, 0, 1, 0, 1, e[i].enemyX1, e[i].enemyX2, e[i].enemyY1, e[i].enemyY2);
					}
					else if (correctAngle < PI / 4 || correctAngle >= 7 * PI / 4) {
						drawTexRect(e[i].enemyTexLeft, 0, 1, 0, 1, e[i].enemyX1, e[i].enemyX2, e[i].enemyY1, e[i].enemyY2);
					}
					else if (correctAngle < 3 * PI / 4 && correctAngle >= PI / 4) {
						drawTexRect(e[i].enemyTexFront, 0, 1, 0, 1, e[i].enemyX1, e[i].enemyX2, e[i].enemyY1, e[i].enemyY2);
					}
					else if (correctAngle < 5 * PI / 4 && correctAngle >= 3 * PI / 4) {
						drawTexRect(e[i].enemyTexRight, 0, 1, 0, 1, e[i].enemyX1, e[i].enemyX2, e[i].enemyY1, e[i].enemyY2);
					}
				}
				else { //if enemy is dead
					if (e[i].enemyTexFront == e[i].enemyDead4) {
						e[i].enemyY1 = SCREEN_HEIGHT / 2;
						e[i].enemyY2 = (SCREEN_HEIGHT / 2) + (((SCREEN_HEIGHT) / e[i].distToPlayer) * 7);
					}
					drawTexRect(e[i].enemyTexFront, 0, 1, 0, 1, e[i].enemyX1, e[i].enemyX2 * 1.2, e[i].enemyY1, e[i].enemyY2);
				}
			}
		}
		enemyAI(i);
	}
}

void castRays() {
	float rayToWallDist, diff, correctDist;
	w.wallY1 = SCREEN_HEIGHT / 4;
	diff = fabs(p.pAng - r.rayAngle); //finds difference in player angle and ray angle
	rayToWallDist = (sqrt(((r.rayX2 - r.rayX1) * (r.rayX2 - r.rayX1) + (r.rayY2 - r.rayY1) * (r.rayY2 - r.rayY1)))); //calculates distance from ray to wall
	correctDist = rayToWallDist * cos(diff); //factors in difference in angles to eliminate fisheye effects
	w.wallY2 = w.wallY1 + ((SCREEN_HEIGHT / correctDist) * cellSize);

	float offset;
	float offsetWidth = (1 / 32);

	if (side == 0) {
		offset = fmod(r.rayY2, cellSize) / cellSize;
	}
	else {
		offset = fmod(r.rayX2, cellSize) / cellSize;
	}

	//quick shading
	if (correctDist >= 75) {
		glColor3f(0.6, 0.6, 0.6);
	}
	else if (correctDist >= 62 && correctDist < 75) {
		glColor3f(0.7, 0.7, 0.7);
	}
	else if (correctDist >= 50 && correctDist < 62) {
		glColor3f(0.8, 0.8, 0.8);
	}
	else {
		glColor3f(1, 1, 1);
	}

	if (map[posToTileY][posToTileX] == 1) {
		drawTexRect(w.wallTexture, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}
	else if (map[posToTileY][posToTileX] == 2 || map[posToTileY][posToTileX] == 3) {
		drawTexRect(d.doorTexture, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}
	else if (map[posToTileY][posToTileX] == 4) {
		drawTexRect(w.exitTexture, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}

	if (p.state == 0) { //only cast if player is alive
		castEnemies(rayToWallDist);
		castItems(rayToWallDist);
	}
}

void drawRays() {
	int i, k;
	r.rayX1 = p.pX;
	r.rayY1 = p.pY;
	r.rayAngle = p.pAng - (PI / 6);
	r.numRays = SCREEN_WIDTH / 8;
	for (i = 0; i < r.numRays; i++) {
		w.wallX1 = i * (SCREEN_WIDTH / r.numRays); //how far the rays can be cast across the screen lengthwise depends on rayangle, this is what it is for now
		w.wallX2 = w.wallX1 + (SCREEN_WIDTH / r.numRays);
		r.rayDX = cos(r.rayAngle);
		r.rayDY = sin(r.rayAngle);
		r.rayX2 = r.rayX1;
		r.rayY2 = r.rayY1; //initialize ray positions

		for (k = 0; k < 1000; k++) {
			float oldX = r.rayX2;
			float oldY = r.rayY2;

			r.rayX2 = r.rayX1 + r.rayDX * k;
			r.rayY2 = r.rayY1 + r.rayDY * k;
			posToTileX = (int)(r.rayX2) / cellSize;
			posToTileY = (int)(r.rayY2) / cellSize;

			if (map[posToTileY][posToTileX] == 1 || map[posToTileY][posToTileX] == 4) { //keep going until ray hits something
				//fixes texture stretching on walls
				//oldX position of ray X2/Y2 is compared with current ray X2/Y2 position on tilemap
				//side variable is based on whether posToTileX or posToTileY changed
				if ((int)oldX / cellSize != posToTileX) {
					side = 0;
				}
				else {
					side = 1;
				}
				break;
			}
			else if (map[posToTileY][posToTileX] == 2) {
				//ensures door textures are not warped from depth
				if ((r.rayX1/cellSize) < posToTileX) {
					r.rayX2 += r.rayDX + (cellSize / 2);
				}
				else {
					r.rayX2 -= r.rayDX + (cellSize / 2);
				}

				if ((int)oldX / cellSize != posToTileX) {
					side = 0; //hit vertical side
				}
				else {
					side = 1; //hit horizontal side
				}
				break;
			}
			else if (map[posToTileY][posToTileX] == 3) {
				//ensures door textures are not warped from depth
				if ((r.rayY1 / cellSize) < posToTileY) {
					r.rayY2 += r.rayDY + (cellSize / 2);
				}
				else {
					r.rayY2 -= r.rayDY + (cellSize / 2);
				}

				if ((int)oldX / cellSize != posToTileX) {
					side = 0; //hit vertical side
				}
				else {
					side = 1; //hit horizontal side
				}
				break;
			}

			for (int j = 0; j < numberOfEnemies; j++) { //check to see if ray hits enemy, if so index it
				if (r.rayX2 >= e[j].eX - 3 && r.rayX2 <= e[j].eX + 3) {
					if (r.rayY2 >= e[j].eY - 3 && r.rayY2 <= e[j].eY + 3) {
						if (e[j].rendered == false) {
							e[j].index = i;
							e[j].rendered = true;
							e[j].enemyX1 = e[j].index * (SCREEN_WIDTH / r.numRays) + (SCREEN_WIDTH * 0.03); //adjust offset as needed
							e[j].enemyX2 = e[j].enemyX1 + (SCREEN_WIDTH / r.numRays) * 4;
							//initialize x2 value
						}
					}
				}
			}
			for (int j = 0; j < numberOfItems; j++) { //check to see if ray hits item, if so index it
				if (r.rayX2 >= it[j].iX - 3 && r.rayX2 <= it[j].iX + 3) {
					if (r.rayY2 >= it[j].iY - 3 && r.rayY2 <= it[j].iY + 3) {
						if (it[j].rendered == false) {
							it[j].index = i;
							it[j].rendered = true;
							it[j].itemX1 = it[j].index * (SCREEN_WIDTH / r.numRays) + (SCREEN_WIDTH * 0.03);
							it[j].itemX2 = it[j].itemX1 + (SCREEN_WIDTH / r.numRays) * 2;
							//initialize x2 value
						}
					}
				}
			}
		}

		//draw rays for debugging purposes
		/*glColor3f(0, 1, 0);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2i(r.rayX1, r.rayY1);
		glVertex2i(r.rayX2, r.rayY2);
		glEnd();*/

		castRays();
		r.rayAngle += (60*(PI/180))/r.numRays; //60 degrees in radians divided by numRays
	}
}