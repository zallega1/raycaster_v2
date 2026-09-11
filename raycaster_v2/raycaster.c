#include "raycaster.h"

struct Rays r;

int posToTileX, posToTileY;
int side;
float zBuffer[SCREEN_WIDTH/8];

void castItems() {
	//same logic as castEnemies, but for items
	for (int i = 0; i < numberOfItems; i++) {
		if (it[i].leftIndex != -100 && it[i].pickedUp == false) {
			it[i].itemY1 = SCREEN_HEIGHT / 2;
			it[i].itemY2 = it[i].itemY1 + ((SCREEN_HEIGHT / it[i].distToPlayer) * 4);

			float j1 = it[i].leftIndex;
			float j2 = it[i].rightIndex;

			for (int j = j1; j <= j2; j++) {
				if (it[i].distToPlayer < zBuffer[j]) {
					float t1 = (j - j1) / (j2 - j1);
					float t2 = (j + 1 - j1) / (j2 - j1);

					float sliceStart = j * (SCREEN_WIDTH / r.numRays);
					float sliceEnd = sliceStart + (SCREEN_WIDTH / r.numRays);

					drawTexRect(it[i].itemTexture, t1, t2, 0, 1, sliceStart, sliceEnd, it[i].itemY1, it[i].itemY2);
				}
			}
		}
	}
}

void enemyTexture(int i) {
	if (e[i].enemyHealth > 0) {
		//make angle positive so my head doesn't explode
		float correctAngle = fabs(e[i].angleFacingPlayer);

		//for debugging
		//printf("%f\n", correctAngle);

		if (correctAngle < 7 * PI / 4 && correctAngle >= 5 * PI / 4) {
			e[i].currentTex = eTex[e[i].enemyType].enemyTexBack;
		}
		else if (correctAngle < PI / 4 || correctAngle >= 7 * PI / 4) {
			e[i].currentTex = eTex[e[i].enemyType].enemyTexLeft;
		}
		else if (correctAngle < 3 * PI / 4 && correctAngle >= PI / 4) {
			e[i].currentTex = eTex[e[i].enemyType].enemyTexFront;
		}
		else if (correctAngle < 5 * PI / 4 && correctAngle >= 3 * PI / 4) {
			e[i].currentTex = eTex[e[i].enemyType].enemyTexRight;
		}
	}
	else { //if enemy is dead
		if (e[i].currentTex == eTex[e[i].enemyType].enemyDead4) {
			e[i].enemyY1 = SCREEN_HEIGHT / 2;
			e[i].enemyY2 = (SCREEN_HEIGHT / 2) + (((SCREEN_HEIGHT) / e[i].distToPlayer) * 7);
		}
	}
}

void castEnemies() {
	glColor3f(1, 1, 1);
	for (int i = 0; i < numberOfEnemies; i++) {
		if (e[i].leftIndex != -100) { 
			//y coordinates based on distance to player
			e[i].enemyY1 = SCREEN_HEIGHT / 4;
			e[i].enemyY2 = e[i].enemyY1 + ((SCREEN_HEIGHT / e[i].distToPlayer) * 16);

			//determine which sprite to be cast based on angle to player
			enemyTexture(i);

			//loop through indexed rays
			//would use r instead of j but the ray struct is r and i don't want to change it
			float j1 = e[i].leftIndex;
			float j2 = e[i].rightIndex;

			for (int j = j1; j <= j2; j++) {
				//compare player distance to distance stored in z buffer
				if (e[i].distToPlayer < zBuffer[j]) {

					//texture slices, gotta be between 0 and 1
					float t1 = (j - j1)/(j2 - j1);
					float t2 = (j + 1 - j1)/(j2 - j1);

					//find starting x position of slice, then use that to determine end position
					float sliceStart = j * (SCREEN_WIDTH / r.numRays);
					float sliceEnd = sliceStart + (SCREEN_WIDTH / r.numRays);

					drawTexRect(e[i].currentTex, t1, t2, 0, 1, sliceStart, sliceEnd, e[i].enemyY1, e[i].enemyY2);
				}
			}
		}
	}
}

void castRays(int i) {
	float rayToWallDist, diff, correctDist;
	w.wallY1 = SCREEN_HEIGHT / 4;
	diff = fabs(p.pAng - r.rayAngle); //finds difference in player angle and ray angle
	rayToWallDist = (sqrt(((r.rayX2 - r.rayX1) * (r.rayX2 - r.rayX1) + (r.rayY2 - r.rayY1) * (r.rayY2 - r.rayY1)))); //calculates distance from ray to wall
	correctDist = rayToWallDist * cos(diff); //factors in difference in angles to eliminate fisheye effects
	w.wallY2 = w.wallY1 + ((SCREEN_HEIGHT / correctDist) * cellSize);

	zBuffer[i] = rayToWallDist; //store distance in z buffer for sprite casting

	float offset;
	float offsetWidth = (1 / 32); //textures are 32x32

	if (side == 0) {
		offset = fmod(r.rayY2, cellSize) / cellSize;
	}
	else {
		offset = fmod(r.rayX2, cellSize) / cellSize;
	}

	//quick shading
	if (correctDist > 125) {
		glColor3f(0.3, 0.3, 0.3);
	}
	else if (correctDist >= 100 && correctDist < 125) {
		glColor3f(0.4, 0.4, 0.4);
	}
	else if (correctDist >= 87 && correctDist < 100) {
		glColor3f(0.5, 0.5, 0.5);
	}
	else if (correctDist >= 75 && correctDist < 87) {
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
		w.currentTex = wallTex.tex1;
		//drawTexRect(w.wallTexture, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}
	else if (map[posToTileY][posToTileX] == 2 || map[posToTileY][posToTileX] == 3) {
		w.currentTex = doorTex;
		//drawTexRect(doorTex, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}
	else if (map[posToTileY][posToTileX] == 4) {
		w.currentTex = wallTex.exitTex;
		//drawTexRect(w.exitTexture, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
	}
	else if (map[posToTileY][posToTileX] == 5) {
		w.currentTex = wallTex.tex2;
	}
	drawTexRect(w.currentTex, offset, offset + offsetWidth, 0, 1, w.wallX1, w.wallX2, w.wallY1, w.wallY2);
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

			if (map[posToTileY][posToTileX] == 1 || map[posToTileY][posToTileX] == 4 || map[posToTileY][posToTileX] == 5) { //keep going until ray hits something
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
				int center;
				for (int j = 0; j < numberOfDoors; j++) {
					if (d[j].dTileX == posToTileX && d[j].dTileY == posToTileY) {
						center = d[j].dCenter;
						break;
					}
				}
				if (r.rayX2 >= center - 1 && r.rayX2 <= center + 1) {
					if ((int)oldX / cellSize != posToTileX) { //flip sides for vertical wall
						side = 1; //hit vertical side
					}
					else {
						side = 0; //hit horizontal side
					}
					break;
				}
			}
			else if (map[posToTileY][posToTileX] == 3) {
				//ensures door textures are not warped from depth
				int center;
				for (int j = 0; j < numberOfDoors; j++) {
					if (d[j].dTileX == posToTileX && d[j].dTileY == posToTileY) {
						center = d[j].dCenter;
						break;
					}
				}
				if (r.rayY2 >= center - 1 && r.rayY2 <= center + 1) {
					if ((int)oldX / cellSize != posToTileX) {
						side = 0; //hit vertical side
					}
					else {
						side = 1; //hit horizontal side
					}
					break;
				}
			}

			for (int j = 0; j < numberOfEnemies; j++) { //check to see if ray hits enemy, if so index it
				if ((r.rayX2 >= e[j].eX - 3 && r.rayX2 <= e[j].eX + 3) && (r.rayY2 >= e[j].eY - 3 && r.rayY2 <= e[j].eY + 3)) {
					if (e[j].leftIndex == -100) {
						e[j].leftIndex = i;
					}
					e[j].rightIndex = i;
				}
			}
			for (int j = 0; j < numberOfItems; j++) { //check to see if ray hits item, if so index it
				if ((r.rayX2 >= it[j].iX - 1 && r.rayX2 <= it[j].iX + 1) && (r.rayY2 >= it[j].iY - 1 && r.rayY2 <= it[j].iY + 1)) {
					if (it[j].leftIndex == -100) {
						it[j].leftIndex = i;
					}
					it[j].rightIndex = i;
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

		castRays(i);
		r.rayAngle += (60*(PI/180))/r.numRays; //60 degrees in radians divided by numRays
	}
	if (p.state == ALIVE) { //only cast if player is alive
		castEnemies();
		castItems();
	}
}