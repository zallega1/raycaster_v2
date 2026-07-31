#include "item.h"

struct Item it[MAX_ITEMS];
int numberOfItems;

/* ITEM TYPES
	1 = HEALTH PACK
	2 = AMMO PACK 
*/

void initItems() { //initItems, createItem, and drawItem follow same logic as enemy functions
	numberOfItems = 0;
	if (level = 1) {
		createItem(100, 30, 2, numberOfItems);
		createItem(135, 170, 1, numberOfItems);
		createItem(135, 230, 2, numberOfItems);
	}
}

void createItem(float itemX, float itemY, int itemType, int num) {
	it[num].iX = itemX;
	it[num].iY = itemY;
	it[num].pickedUp = false;
	it[num].itemType = itemType;
	switch (it[num].itemType) {
	case 1:
		it[num].itemTexture = loadTexture("textures/items/medkit.png");
		break;
	case 2:
		it[num].itemTexture = loadTexture("textures/hud/ammo.png");
		break;
	}
	numberOfItems += 1;
}

void drawItem(int num) {
	for (int k = 0; k < num; k++) {
		/*glColor3f(0, 0, 1);
		glPointSize(4);
		glBegin(GL_POINTS);
		glVertex2f(it[k].iX, it[k].iY);
		glEnd();*/

		float xDiff, yDiff;
		xDiff = p.pX - it[k].iX;
		yDiff = p.pY - it[k].iY;
		it[k].leftIndex = -100;
		it[k].rightIndex = -100;
		it[k].distToPlayer = sqrt((xDiff * xDiff) + (yDiff * yDiff));
		if (it[k].distToPlayer < 4) {
			pickupItem(k);
		}
	}
}

void pickupItem(int num) {
	if (it[num].pickedUp == false) { //within one pixel of item (doesn't need to be exact)
		//printf("standing on item, item is active\n");
		switch (it[num].itemType) {
		case 1:
			healPlayer(num);
			break;
		case 2:
			refillAmmo(num);
			break;
		}
	}
}

void healPlayer(int num) {
	if (p.health < 100) {
		it[num].pickedUp = true;
		p.health += 40;
		if (p.health > 100) {
			p.health = 100; //clamp to 100 health at maximum
		}
	}
}

void refillAmmo(int num) {
	if (g.ammo < 50) {
		it[num].pickedUp = true;
		g.ammo += 10;
		if (g.ammo > 50) {
			g.ammo = 50; //clamp to 50 bullets at maximum
		}
	}
}