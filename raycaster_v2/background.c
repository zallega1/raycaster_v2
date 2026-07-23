#include "background.h"

void drawTitleBackground(int select) {
	glColor3f(0.5, 0.5, 0.5);
	drawRect(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	glColor3f(1, 1, 1);
	drawText("Untitled", SCREEN_WIDTH * 0.2083, SCREEN_WIDTH * 0.2917, SCREEN_HEIGHT * 0.125, SCREEN_HEIGHT * 0.25);
	drawText("FPS Game", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.25, SCREEN_HEIGHT * 0.375);
	if (select == 0) { //start game is selected
		glColor3f(0, 1, 0);
		drawText("Start", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.625, SCREEN_HEIGHT * 0.75);
		glColor3f(1, 1, 1);
		drawText("Quit", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.75, SCREEN_HEIGHT * 0.875);
	}
	else if (select == 1) { //quit is selected
		glColor3f(1, 1, 1);
		drawText("Start", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.625, SCREEN_HEIGHT * 0.75);
		glColor3f(0, 1, 0);
		drawText("Quit", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.75, SCREEN_HEIGHT * 0.875);
	}
	else if (select == -1) { //default state
		glColor3f(1, 1, 1);
		drawText("Start", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.625, SCREEN_HEIGHT * 0.75);
		drawText("Quit", SCREEN_WIDTH * 0.4167, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.75, SCREEN_HEIGHT * 0.875);
	}
}

void drawLevelSelectBackground(int screen) {
	glColor3f(0.25, 0.25, 0.25);
	drawRect(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT);

	glColor3f(1, 1, 1);
	drawText("Level Select", SCREEN_WIDTH * 0.2083, SCREEN_WIDTH * 0.2917, SCREEN_HEIGHT * 0.125, SCREEN_HEIGHT * 0.25);
	if (screen == 0) { //back button selected
		glColor3f(1, 1, 1);
		drawText("Stage 1", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.4375);
		drawText("Stage 2", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.5625);
		drawText("Stage 3", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5625, SCREEN_HEIGHT * 0.6875);
		glColor3f(0, 1, 0);
		drawText("Back", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.6875, SCREEN_HEIGHT * 0.8125);
	}
	else if (screen == 1) { //stage 1 selected
		glColor3f(0, 1, 0);
		drawText("Stage 1", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.4375);
		glColor3f(1, 1, 1);
		drawTexRect(loadTexture("textures/hud/demo1.png"), 0, 1, 0, 1, SCREEN_WIDTH * 0.5, SCREEN_WIDTH * 0.9167, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.8125);
		drawText("Secret Base", SCREEN_WIDTH * 0.4583, SCREEN_WIDTH * 0.5417, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT * 0.9375);
		drawText("Stage 2", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.5625);
		drawText("Stage 3", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5625, SCREEN_HEIGHT * 0.6875);
		drawText("Back", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.6875, SCREEN_HEIGHT * 0.8125);
	}
	else if (screen == 2) {
		glColor3f(0, 1, 0);
		drawText("Stage 2", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.5625);
		glColor3f(1, 1, 1);
		drawText("WIP", SCREEN_WIDTH * 0.5833, SCREEN_WIDTH * 0.6667, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
		drawText("Stage 1", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.4375);
		drawText("Stage 3", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5625, SCREEN_HEIGHT * 0.6875);
		drawText("Back", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.6875, SCREEN_HEIGHT * 0.8125);
	}
	else if (screen == 3) {
		glColor3f(0, 1, 0);
		drawText("Stage 3", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5625, SCREEN_HEIGHT * 0.6875);
		glColor3f(1, 1, 1);
		drawText("WIP", SCREEN_WIDTH * 0.5833, SCREEN_WIDTH * 0.6667, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
		drawText("Stage 1", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.4375);
		drawText("Stage 2", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.5625);
		drawText("Back", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.6875, SCREEN_HEIGHT * 0.8125);
	}
	else if (screen == -1) { //default state
		glColor3f(1, 1, 1);
		drawText("Stage 1", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.3125, SCREEN_HEIGHT * 0.4375);
		drawText("Stage 2", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.5625);
		drawText("Stage 3", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5625, SCREEN_HEIGHT * 0.6875);
		drawText("Back", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.6875, SCREEN_HEIGHT * 0.8125);
	}

}

void drawLevelCompleteBackground(int screen) {
	glColor3f(1, 1, 1);
	drawText("Level Complete", SCREEN_WIDTH * 0.2083, SCREEN_WIDTH * 0.2917, SCREEN_HEIGHT * 0.125, SCREEN_HEIGHT * 0.25);

	if (screen == 0) {
		glColor3f(0, 1, 0);
		drawText("Replay", SCREEN_WIDTH * 0.375, SCREEN_WIDTH * 0.4583, SCREEN_HEIGHT * 0.375, SCREEN_HEIGHT * 0.5);
		glColor3f(1, 1, 1);
		drawText("Level Select", SCREEN_WIDTH * 0.25, SCREEN_WIDTH * 0.33, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
	}
	else if (screen == 1) {
		glColor3f(1, 1, 1);
		drawText("Replay", SCREEN_WIDTH * 0.375, SCREEN_WIDTH * 0.4583, SCREEN_HEIGHT * 0.375, SCREEN_HEIGHT * 0.5);
		glColor3f(0, 1, 0);
		drawText("Level Select", SCREEN_WIDTH * 0.25, SCREEN_WIDTH * 0.33, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
	}
}

void drawLevelBackground(int level) {
	if (level == 1) {
		glColor3f(0.07, 0.07, 0.13);
		drawRect(0, SCREEN_WIDTH, SCREEN_HEIGHT * 0.8125, SCREEN_HEIGHT);

		glColor3f(0.07 * 0.8, 0.07 * 0.8, 0.13 * 0.8);
		drawRect(0, SCREEN_WIDTH, SCREEN_HEIGHT * 0.625, SCREEN_HEIGHT * 0.8125);

		glColor3f(0.07 * 0.7, 0.07 * 0.7, 0.13 * 0.7);
		drawRect(0, SCREEN_WIDTH, SCREEN_HEIGHT * 0.4375, SCREEN_HEIGHT * 0.625);

		glColor3f(0.07 * 0.6, 0.07 * 0.6, 0.13 * 0.6);
		drawRect(0, SCREEN_WIDTH, SCREEN_HEIGHT / 4, SCREEN_HEIGHT * 0.4375);
	}
}