#include "hud.h"

void drawHUD() {
	//load the number sprites
	GLuint number0 = loadTexture("textures/hud/0.png");
	GLuint number1 = loadTexture("textures/hud/1.png");
	GLuint number2 = loadTexture("textures/hud/2.png");
	GLuint number3 = loadTexture("textures/hud/3.png");
	GLuint number4 = loadTexture("textures/hud/4.png");
	GLuint number5 = loadTexture("textures/hud/5.png");
	GLuint number6 = loadTexture("textures/hud/6.png");
	GLuint number7 = loadTexture("textures/hud/7.png");
	GLuint number8 = loadTexture("textures/hud/8.png");
	GLuint number9 = loadTexture("textures/hud/9.png");

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
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.7917, SCREEN_WIDTH * 0.875, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num2) {
	case 0:
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.833, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num1) {
	case 0:
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.875, SCREEN_WIDTH * 0.9583, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	int num4, num5, num6;
	num6 = p.health / 100;
	num5 = (p.health / 10) % 10;
	num4 = p.health % 10;

	switch (num6) {
	case 0:
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.0416, SCREEN_WIDTH * 0.125, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num5) {
	case 0:
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.0833, SCREEN_WIDTH * 0.1667, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}

	switch (num4) {
	case 0:
		drawTexRect(number0, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 1:
		drawTexRect(number1, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 2:
		drawTexRect(number2, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 3:
		drawTexRect(number3, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 4:
		drawTexRect(number4, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 5:
		drawTexRect(number5, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 6:
		drawTexRect(number6, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 7:
		drawTexRect(number7, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 8:
		drawTexRect(number8, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	case 9:
		drawTexRect(number9, 0, 1, 0, 1, SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		break;
	}
}