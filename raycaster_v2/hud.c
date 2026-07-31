#include "hud.h"

void drawHUD() {
	GLuint ammo = loadTexture("textures/hud/ammo.png");
	GLuint health = loadTexture("textures/hud/health.png");

	glColor3f(1, 1, 1);
	drawTexRect(ammo, 0, 1, 0, 1, SCREEN_WIDTH * 0.7708, SCREEN_WIDTH * 0.8542, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
	drawTexRect(health, 0, 1, 0, 1, SCREEN_WIDTH * 0.1458, SCREEN_WIDTH * 0.2292, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);

	int num1, num2, num3; //for ammo count in HUD
	num3 = g.ammo / 100;
	num2 = (g.ammo / 10) % 10;
	num1 = g.ammo % 10;

	switch (num3) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num2) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num1) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	int num4, num5, num6;
	num6 = p.health / 100;
	num5 = (p.health / 10) % 10;
	num4 = p.health % 10;

	switch (num6) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num5) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num4) {
	case 0:
		drawTexRect(font.num[0], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(font.num[1], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(font.num[2], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(font.num[3], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(font.num[4], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(font.num[5], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(font.num[6], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(font.num[7], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(font.num[8], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(font.num[9], 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}
}