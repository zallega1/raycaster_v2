#include "door.h"

struct Door d[MAX_DOORS];
GLuint doorTex;
int numberOfDoors;

void createDoor(int doorTileX, int doorTileY, int num, int type) {
	d[num].dTileX = doorTileX;
	d[num].dTileY = doorTileY;
	d[num].type = type;
	d[num].isOpened = false;
	d[num].inRange = false;
	numberOfDoors += 1;
}

void initDoors() {
	numberOfDoors = 0;
	if (level == 1) {
		doorTex = loadTexture("textures/walls/door.png");
		createDoor(7, 4, numberOfDoors, 2);
		createDoor(12, 7, numberOfDoors, 3);
		createDoor(9, 10, numberOfDoors, 2);
		createDoor(15, 10, numberOfDoors, 2);
		createDoor(9, 14, numberOfDoors, 2);
		createDoor(15, 14, numberOfDoors, 2);
		createDoor(19, 17, numberOfDoors, 2);
	}
}

void openDoor(int num) {
	static float t;

	if (d[num].isOpened == true && t == 0) {
		t = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - t;

	if (elapsedTime < 3) {
		map[d[num].dTileY][d[num].dTileX] = 0;
	}
	else {
		map[d[num].dTileY][d[num].dTileX] = d[num].type;
		d[num].isOpened = false;
		t = 0;
	}
}