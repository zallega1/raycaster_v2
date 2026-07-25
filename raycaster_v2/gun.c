#include "gun.h"

struct Gun g;
struct GunTex gTex[GUN_ARR_SIZE];

void loadGunTex(int num) {
	switch (num) {
	case 0:
	case 1:
		gTex[num].gunTexture = loadTexture("textures/guns/pistol-1.png");
		gTex[num].gunTexture2 = loadTexture("textures/guns/pistol-2.png");
		gTex[num].gunTexture3 = loadTexture("textures/guns/pistol-3.png");
		break;
	case 2:
		//will finish later
		break;
	}
}

void initWeapon() {
	g.weapon = 1;
	g.ammo = 30;
	g.isFired = false;
	for (int i = 1; i < GUN_ARR_SIZE; i++) {
		loadGunTex(i);
	}
}

void drawWeapon(int num) {
	g.weapon = num;
	if (g.weapon == 1) { //pistol (default)
		g.gunW = SCREEN_WIDTH * 0.387;
		g.gunH = SCREEN_HEIGHT * 0.64;
		g.gunX = (SCREEN_WIDTH / 2) - (g.gunW / 2) + g.gunXOffset; //half of screen width minus offset of gun sprite
		g.gunY = SCREEN_HEIGHT - g.gunH + g.gunYOffset; //screen height plus offset of gun sprite
	}

	if (g.isFired == false) {
		g.currentTex = gTex[g.weapon].gunTexture;
	}

	glColor3f(1, 1, 1);
	drawTexRect(g.currentTex, 0, 1, 0, 1, g.gunX, g.gunX + g.gunW, g.gunY, g.gunY + g.gunH);
	sway();
}

void sway() {
	static int yDir; //0 for stop, 1 for up, 2 for down
	if (k.w == 1 || k.s == 1) {
		float t = glfwGetTime();
		float speed = 5; 
		float amp = 80; //amplitude
		if (yDir == 1 || yDir == 0) {
			g.gunYOffset -= 2;
			if (g.gunYOffset <= -15) {
				yDir = 2;
			}
		}
		else {
			g.gunYOffset += 2;
			if (g.gunYOffset >= 15) {
				yDir = 1;
			}
		}
		g.gunXOffset = sin(t * speed) * amp;
	}
	else {
		g.gunXOffset *= 0.8;
		g.gunYOffset *= 0.2;
		if (g.gunYOffset <= 0.1 || g.gunYOffset >= 0.1) {
			g.gunYOffset = 0;
			yDir = 0;
		}
	}
}

void fireGun(float deltaTime) {
	static float t;

	if (g.isFired == true && t == 0) {
		t = glfwGetTime();
	}

	float currentTime = glfwGetTime() - t;

	if (g.weapon == 1) {
		if (currentTime < 0.15) {
			g.currentTex = gTex[g.weapon].gunTexture2;
			//printf("gun frame 2 \n");
		}
		else if (currentTime < 0.3) {
			g.currentTex = gTex[g.weapon].gunTexture3;
			//printf("gun frame 3 \n");
		}
		else {
			g.currentTex = gTex[g.weapon].gunTexture;
			//printf("gun frame 1 \n");
			b.bX = p.pX;
			b.bY = p.pY; //bullet starts at player position
			fireBullet(deltaTime, g.weapon);
			g.isFired = false;
			g.ammo -= 1;
			t = 0;
		}
	}
}