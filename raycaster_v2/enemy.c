#include "enemy.h"

struct Enemy e[10];
struct EnemyTex eTex[3];
int numberOfEnemies;
int enemyKills;

void loadEnemyTex(int num) {
	switch (num) {
	case 0:
	case 1:
		eTex[num].enemyTexFront = loadTexture("textures/enemy/enemy1_front.png");
		eTex[num].enemyTexBack = loadTexture("textures/enemy/enemy1_back.png");
		eTex[num].enemyTexLeft = loadTexture("textures/enemy/enemy1_left.png");
		eTex[num].enemyTexRight = loadTexture("textures/enemy/enemy1_right.png");
		eTex[num].enemyDead1 = loadTexture("textures/enemy/enemy1dead1.png");
		eTex[num].enemyDead2 = loadTexture("textures/enemy/enemy1dead2.png");
		eTex[num].enemyDead3 = loadTexture("textures/enemy/enemy1dead3.png");
		eTex[num].enemyDead4 = loadTexture("textures/enemy/enemy1dead4.png");
		eTex[num].enemyShoot1 = loadTexture("textures/enemy/enemy1_shoot1.png");
		eTex[num].enemyShoot2 = loadTexture("textures/enemy/enemy1_shoot2.png");
		eTex[num].enemyWalk1 = loadTexture("textures/enemy/enemy1walk1.png");
		eTex[num].enemyWalk2 = loadTexture("textures/enemy/enemy1walk2.png");
		eTex[num].enemyWalk3 = loadTexture("textures/enemy/enemy1walk3.png");
		eTex[num].enemyWalk4 = loadTexture("textures/enemy/enemy1walk4.png");
		break;
	case 2:
		//will add later
		break;
	}
}

void initEnemies() {
	numberOfEnemies = 0; //reset counter to zero
	for (int i = 1; i < ENEMY_ARR_SIZE; i++) {
		loadEnemyTex(i);
	}

	if (level == 1) {
		createEnemy(200, 50, 1, numberOfEnemies, -PI);
		createEnemy(230, 300, 1, numberOfEnemies, -PI/2);
		createEnemy(180, 150, 1, numberOfEnemies, 0);
		createEnemy(190, 300, 1, numberOfEnemies, -PI / 2);
		createEnemy(260, 170, 1, numberOfEnemies, -PI);
		createEnemy(290, 230, 1, numberOfEnemies, -PI);
		createEnemy(360, 320, 1, numberOfEnemies, -3*PI/4);
		createEnemy(380, 275, 1, numberOfEnemies, -PI);
	}
}

void animateDeath(int num) {
	static float t;

	if (t == 0) {
		t = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - t;

	if (elapsedTime < 0.1) {
		e[num].currentTex = eTex[e[num].enemyType].enemyDead1;
	}
	else if (elapsedTime < 0.2) {
		e[num].currentTex = eTex[e[num].enemyType].enemyDead2;
	}
	else if (elapsedTime < 0.3) {
		e[num].currentTex = eTex[e[num].enemyType].enemyDead3;
	}
	else {
		e[num].currentTex = eTex[e[num].enemyType].enemyDead4;
		t = 0;
	}
}

void enemyTakeDamage(int num, int playerWeapon) {
	switch (playerWeapon) {
	case 0:
	case 1:
		e[num].enemyHealth -= 50;
		break;
	case 2:
		//will finish later
		break;
	}

	if (e[num].enemyHealth <= 0) { //no negative health values
		e[num].enemyHealth = 0; //set to 0
		if (e[num].enemyState != 3) {
			enemyKills += 1;
		}
		e[num].enemyState = 3; //enemy death state
	}
	else {
		e[num].enemyState = 1; //set enemy to active state if not already
	}
	b.hitEnemy = true;
}

bool enemyCheckCollision(int num) {
	int enemyXToTile = (int)(e[num].eX + e[num].edX) / cellSize; //check tile for wall collision
	int enemyYToTile = (int)(e[num].eY + e[num].edY) / cellSize;
	if (map[enemyYToTile][enemyXToTile] != 0) {
		return true;
	}
	if (e[num].distToPlayer <= 10) { //check for collision with player
		e[num].enemyState = 2; //if the enemy gets close instead of randomly deciding when to shoot they just start blasting
		return true;
	}
	return false;
}

void enemyShoot(int num) {
	static float t;

	if (e[num].enemyState == 2 && t == 0) {
		t = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - t;

	if (elapsedTime < 0.15) {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyShoot1;
	}
	else if (elapsedTime < 0.3) {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyShoot2;
	}
	else {
		//fire the bullet
		e[num].eBX = e[num].eX;
		e[num].eBY = e[num].eY;
		e[num].hitPlayer = false;

		int ebxToMap = (int)(e[num].eBX) / cellSize;
		int ebyToMap = (int)(e[num].eBY) / cellSize;

		while (map[ebyToMap][ebxToMap] == 0 && e[num].hitPlayer == false) {
			//draw path for debug purposes
			/*glColor3f(0, 1, 0);
			glPointSize(4);
			glBegin(GL_POINTS);
			glVertex2i(e[num].eBX, e[num].eBY);
			glEnd();*/

			e[num].eBX += e[num].edX * (5 * e[num].time);
			ebxToMap = (int)(e[num].eBX) / cellSize;
			e[num].eBY += e[num].edY * (5 * e[num].time);
			ebyToMap = (int)(e[num].eBY) / cellSize;

			if (e[num].eBX <= p.pX + 3 && e[num].eBX >= p.pX - 3) {
				if (e[num].eBY >= p.pY - 3 && e[num].eBY <= p.pY + 3) {
					//printf("player hit\n");
					e[num].hitPlayer = true;
					e[num].eBX = -100; //move bullet offscreen
					e[num].eBY = -100;
					damagePlayer(e[num].enemyType);
				}
			}
		}

		e[num].enemyState = 1;
		t = 0;
	}
}

void lookForPlayer(int num) {
	e[num].rayX1 = e[num].eX;
	e[num].rayY1 = e[num].eY;
	e[num].rayX3 = e[num].eX;
	e[num].rayY3 = e[num].eY;
	e[num].rayAngle = e[num].enemyAngle - PI/6;
	e[num].rayAngle2 = e[num].enemyAngle + PI/6;

	e[num].rayDX = cos(e[num].rayAngle); //initialize ray angles
	e[num].rayDY = sin(e[num].rayAngle);
	e[num].rayDX2 = cos(e[num].rayAngle2);
	e[num].rayDY2 = sin(e[num].rayAngle2);

	e[num].rayX2 = e[num].rayX1;
	e[num].rayY2 = e[num].rayY1; //initialize ray positions

	for (int i = 0; i < 200; i++) {
		e[num].rayX2 = e[num].rayX1 + e[num].rayDX * i;
		e[num].rayY2 = e[num].rayY1 + e[num].rayDY * i;

		e[num].posToTileX = (int)(e[num].rayX2) / cellSize;
		e[num].posToTileY = (int)(e[num].rayY2) / cellSize;

		if (map[e[num].posToTileY][e[num].posToTileX] == 1) { //keep going until ray hits something
			break;
		}
		else if (map[e[num].posToTileY][e[num].posToTileX] == 2) {
			if ((e[num].rayX1 / cellSize) < e[num].posToTileX) {
				e[num].rayX2 += e[num].rayDX + (cellSize / 2);
			}
			else {
				e[num].rayX2 -= e[num].rayDX + (cellSize / 2);
			}
			break;
		}
		else if (map[e[num].posToTileY][e[num].posToTileX] == 3) {
			if ((e[num].rayY1 / cellSize) < e[num].posToTileY) {
				e[num].rayY2 += e[num].rayDY + (cellSize / 2);
			}
			else {
				e[num].rayY2 -= e[num].rayDY + (cellSize / 2);
			}
			break;
		}

	}
	for (int k = 0; k < 200; k++) {
		e[num].rayX4 = e[num].rayX3 + e[num].rayDX2 * k;
		e[num].rayY4 = e[num].rayY3 + e[num].rayDY2 * k;

		e[num].posToTileX2 = (int)(e[num].rayX4) / cellSize;
		e[num].posToTileY2 = (int)(e[num].rayY4) / cellSize;

		if (map[e[num].posToTileY2][e[num].posToTileX2] == 1) { //keep going until ray hits something
			break;
		}
		else if (map[e[num].posToTileY2][e[num].posToTileX2] == 2) {
			if ((e[num].rayX3 / cellSize) < e[num].posToTileX2) {
				e[num].rayX4 += e[num].rayDX2 + (cellSize / 2);
			}
			else {
				e[num].rayX4 -= e[num].rayDX2 + (cellSize / 2);
			}
			break;
		}
		else if (map[e[num].posToTileY2][e[num].posToTileX2] == 3) {
			if ((e[num].rayY3 / cellSize) < e[num].posToTileY2) {
				e[num].rayY3 += e[num].rayDY2 + (cellSize / 2);
			}
			else {
				e[num].rayY3 -= e[num].rayDY2 + (cellSize / 2);
			}
			break;
		}

	}

	//lot of math down here
	float vX1 = e[num].rayX2 - e[num].rayX1; //vector calculations
	float vX2 = e[num].rayX4 - e[num].rayX3;
	float vY1 = e[num].rayY2 - e[num].rayY1;
	float vY2 = e[num].rayY4 - e[num].rayY3;
	float vPX = p.pX - e[num].rayX1;
	float vPY = p.pY - e[num].rayY1;
	float cross1 = (vX1*vPY) - (vY1*vPX); //cross products
	float cross2 = (vPX*vY2) - (vPY*vX2);

	float checkRangeX = e[num].rayX1;
	float checkRangeY = e[num].rayY1;
	float distanceToPlayer = sqrt((vPX*vPX) + (vPY*vPY)); //get tangent
	float checkDX = vPX / distanceToPlayer;
	float checkDY = vPY / distanceToPlayer;
	bool pathClear = false; //checks if there is a wall between player and enemy

	for (int i = 0; i < distanceToPlayer; i++) {
		checkRangeX = e[num].rayX1 + checkDX * i;
		checkRangeY = e[num].rayY1 + checkDY * i;

		int rangeToTileX = (int)(checkRangeX) / cellSize;
		int rangeToTileY = (int)(checkRangeY) / cellSize;

		if (map[rangeToTileY][rangeToTileX] != 0) {
			pathClear = false;
			break;
		}

		pathClear = true; //if path can be established to player
	}

	if (cross1 > 0 && cross2 > 0 && pathClear == true) { //if player is in between lines AND is not obscured
		//printf("found you\n");
		e[num].enemyState = 1;
	}

	//for debugging 
	/*glColor3f(0, 1, 0);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(e[num].rayX1, e[num].rayY1);
	glVertex2i(e[num].rayX2, e[num].rayY2);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(e[num].rayX3, e[num].rayY3);
	glVertex2i(e[num].rayX4, e[num].rayY4);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(e[num].rayX1, e[num].rayY1);
	glVertex2i(checkRangeX, checkRangeY);
	glEnd();*/
}

void animateWalk(int num) {
	static float t;

	if (t == 0) {
		t = glfwGetTime();
	}

	float elapsedTime = glfwGetTime() - t;

	if (elapsedTime < 0.3) {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyWalk1;
	}
	else if (elapsedTime < 0.6) {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyWalk2;
	}
	else if (elapsedTime < 0.9) {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyWalk3;
	}
	else {
		eTex[e[num].enemyType].enemyTexFront = eTex[e[num].enemyType].enemyWalk4;
		t = 0;
	}
}

void trackPlayer(int num) {
	//first turn to face player
	e[num].angleFacingPlayer = -PI / 2;

	e[num].rayX1 = e[num].eX;
	e[num].rayY1 = e[num].eY;
	e[num].rayX2 = p.pX;
	e[num].rayY2 = p.pY;

	//for debugging
	/*glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	glVertex2f(e[num].rayX1, e[num].rayY1);
	glVertex2f(e[num].rayX2, e[num].rayY2);
	glEnd();*/

	float diffX = e[num].rayX2 - e[num].rayX1;
	float diffY = e[num].rayY2 - e[num].rayY1;

	e[num].enemyAngle = atan2(diffY, diffX);

	//change direction of enemy for movement purposes
	e[num].edX = cos(e[num].enemyAngle);
	e[num].edY = sin(e[num].enemyAngle);

	if (e[num].eX != p.pX && e[num].eY != p.pY) {
		if (enemyCheckCollision(num)) {
			e[num].enemySpeed = 0; //if speed is 0, enemy will not move
		}
		else {
			e[num].enemySpeed = 0.03 * e[num].time;
		}
		e[num].eX += e[num].edX * e[num].enemySpeed; //enemy moves
		e[num].eY += e[num].edY * e[num].enemySpeed;
		animateWalk(num);
		if (rand() % 50000 == 0) {
			//printf("im shooting you haha\n"); //enemy will shoot
			e[num].enemyState = 2;
		}
	}
}

void enemyAI(int num) {
	if (e[num].enemyState == 0) { //enemy is idle, looking for player
		lookForPlayer(num);
	}
	else if (e[num].enemyState == 1) { //enemy has seen player
		trackPlayer(num);
	}
	else if (e[num].enemyState == 2) {
		enemyShoot(num);
	}
	else if (e[num].enemyState == 3) {
		if (e[num].currentTex != eTex[e[num].enemyType].enemyDead4) {
			animateDeath(num);
		}
	}
}

void createEnemy(float enemyX, float enemyY, int type, int num, float angle) {
	e[num].eX = enemyX;
	e[num].eY = enemyY;
	e[num].enemyAngle = angle;
	e[num].edX = cos(e[num].enemyAngle);
	e[num].edY = sin(e[num].enemyAngle);
	e[num].enemyType = type;
	e[num].enemyHealth = 100;
	e[num].enemyState = 0;
	e[num].eBX = -100; //move bullet offscreen
	e[num].eBY = -100;
	numberOfEnemies += 1; //increment by one for each enemy created
}

void drawEnemy(int num, float deltaTime) {
	for (int i = 0; i < num; i++) {
		e[i].time = deltaTime;
		//for debugging
		//glColor3f(1, 0, 0);
		//glPointSize(8);
		//glBegin(GL_POINTS);
		//glVertex2f(e[i].eX, e[i].eY);
		//glEnd();
		///*printf("enemy x pos: %f\n", e[i].eX);
		//printf("enemy y pos: %f\n", e[i].eY);*/

		//glPointSize(2);
		//glColor3f(1, 0, 0);
		//glBegin(GL_LINES);
		//glVertex2f(e[i].eX, e[i].eY);
		//glVertex2f(e[i].eX + e[i].edX * 7.5, e[i].eY + e[i].edY * 7.5);
		//glEnd();

		//angle facing player ray, for debugging
		/*glPointSize(2);
		glColor3f(0, 1, 0);
		glBegin(GL_LINES);
		glVertex2f(e[i].eX, e[i].eY);
		glVertex2f(e[i].eX + cos(e[i].angleFacingPlayer) * 7.5, e[i].eY + sin(e[i].angleFacingPlayer) * 7.5);
		glEnd();*/

		float xDiff, yDiff;
		xDiff = p.pX - e[i].eX;
		yDiff = p.pY - e[i].eY;
		e[i].rendered = false;
		e[i].index = -100;
		e[i].distToPlayer = sqrt((xDiff * xDiff) + (yDiff * yDiff));

		e[i].rayX1 = e[i].eX;
		e[i].rayY1 = e[i].eY;

		if (e[i].enemyState == 0) {
			e[i].angleFacingPlayer = e[i].enemyAngle - p.pAng + (PI / 2);
			if (e[i].angleFacingPlayer <= -2 * PI) {
				e[i].angleFacingPlayer += 2 * PI;
			}
		}
	}
}
