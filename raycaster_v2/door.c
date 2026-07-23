#include "door.h"

struct Door d;

void openDoor(int tileX, int tileY, int type) {
	static float t;

	if (d.isOpened == true && t == 0) {
		t = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - t;

	if (elapsedTime < 1) {
		map[tileY][tileX] = 0;
	}
	else {
		map[tileY][tileX] = type;
		d.isOpened = false;
		t = 0;
	}
}