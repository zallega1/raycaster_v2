#include "door.h"

struct Door d[MAX_DOORS];
GLuint doorTex;
int numberOfDoors;

void createDoor(int doorTileX, int doorTileY, int num, int type, int key) {
	d[num].dTileX = doorTileX;
	d[num].dTileY = doorTileY;
	d[num].type = type;
	d[num].isOpened = false;
	d[num].inRange = false;
	numberOfDoors += 1;
	d[num].key = key;
}

void initDoors() {
	numberOfDoors = 0;
	if (level == 1) {
		doorTex = loadTexture("textures/walls/door.png");
		createDoor(7, 4, numberOfDoors, 2, 0);
		createDoor(12, 7, numberOfDoors, 3, 0);
		createDoor(9, 10, numberOfDoors, 2, 0);
		createDoor(15, 10, numberOfDoors, 2, 0);
		createDoor(9, 14, numberOfDoors, 2, 0);
		createDoor(15, 14, numberOfDoors, 2, 0);
		createDoor(19, 17, numberOfDoors, 2, 0);
		createDoor(15, 4, numberOfDoors, 2, 1);
	}
}

void openDoor(int num) {
	if (d[num].isOpened == true && d[num].time == 0) {
		d[num].time = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - d[num].time;

	if (elapsedTime < 3) {
		map[d[num].dTileY][d[num].dTileX] = 0;
	}
	else {
		map[d[num].dTileY][d[num].dTileX] = d[num].type;
		d[num].isOpened = false;
		d[num].time = 0;
	}
}