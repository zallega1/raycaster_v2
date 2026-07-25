#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <GLFW/glfw3.h>
#include "draw.h"
#include "map.h"
#include "player.h"
#include "keys.h"
#include "background.h"
#include "raycaster.h"
#include "wall.h"
#include "gun.h"
#include "door.h"
#include "hud.h"
#include "enemy.h"
#include "item.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200
#define PI 3.14159

//Main program loop for raycaster

GLFWwindow* window;
int gameState; //0 = title screen, 1 = level select, 2 = settings, 3 = game start, 4 = level complete
int titleSelect; //0 = start, 1 = quit
int levelSelect; //0 = back, 1 = level 1, 2 = level 2, 3 = level 3
int completeSelect; //0 = restart, 1 = back to level select

void init() { //initialize the screen on program startup
    glClearColor(0.2, 0.2, 0.2, 0);
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1);
    gameState = 0;
    titleSelect = -1;
    levelSelect = -1;
    completeSelect = -1;
}

float deltaX; //for mouse controls
float lastTime, currentTime, deltaTime;
bool levelInit; //flag for game start

void display() { //display the graphics
    //needed to calculate speed of movement
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    if (gameState == 0) {
        glfwWaitEventsTimeout(0.5);
        drawTitleBackground(titleSelect);
        levelInit = false;
        if (k.down == 1) {
            titleSelect += 1;
            if (titleSelect > 1) {
                titleSelect = 0;
            }
        }
        if (k.up == 1) {
            titleSelect -= 1;
            if (titleSelect < 0) {
                titleSelect = 1;
            }
        }

        if ((k.space == 1 || k.enter == 1) && titleSelect == 0) {
            levelSelect = 1;
            gameState = 1;
        }
        else if (((k.space == 1 || k.enter == 1) && titleSelect == 1)) {
            glfwTerminate();
        }
    }
    else if (gameState == 1) {
        glfwWaitEventsTimeout(0.5);
        drawLevelSelectBackground(levelSelect);
        if ((k.space == 1 || k.enter == 1) && levelSelect == 1) {
            gameState = 3;
        }
        else if ((k.space == 1 || k.enter == 1) && levelSelect == 0) {
            titleSelect = 0;
            gameState = 0;
        }

        if (k.down == 1) {
            levelSelect += 1;
            glfwWaitEventsTimeout(0.5);
            if (levelSelect > 3) {
                levelSelect = 0;
            }
        }
        if (k.up == 1) {
            levelSelect -= 1;
            glfwWaitEventsTimeout(0.5);
            if (levelSelect < 0) {
                levelSelect = 3;
            }
        }
    }
    else if (gameState == 2) {
        //todo: settings menu
    }
    else if (gameState == 3) {
        if (levelInit == false) {
            initMap();
            initPlayer();
            initWeapon();
            initEnemies();
            initItems();
            initDoors();
            w.wallTexture = loadTexture("textures/walls/wall.png");
            w.exitTexture = loadTexture("textures/walls/exit.png");
            drawWeapon(1);
            levelInit = true;
        }
        //what to draw when player is alive
        if (p.state == 0) {
            p.speed = 50 * deltaTime;
            float pAngSide; //angle for strafing movement
            //player movement
            if (k.left == 1) { // rotate player counterclockwise
                p.pAng -= 4 * deltaTime;
                if (p.pAng < 0) {
                    p.pAng += 2 * PI;
                }
            }
            if (k.right == 1) { // rotate player clockwise
                p.pAng += 4 * deltaTime;
                if (p.pAng > 2 * PI) {
                    p.pAng -= 2 * PI;
                }
            }
            if (k.w == 1) {
                if (!checkCollision(p.pX + p.dX * p.speed, p.pY + p.dY * p.speed)) {
                    p.pX += p.dX * p.speed;
                    p.pY += p.dY * p.speed;
                }
            }
            if (k.s == 1) {
                if (!checkCollision(p.pX - p.dX * p.speed, p.pY - p.dY * p.speed)) {
                    p.pX -= p.dX * p.speed;
                    p.pY -= p.dY * p.speed;
                }
            }
            if (k.a == 1) {
                pAngSide = p.pAng - (PI / 2);
                if (!checkCollision(p.pX + cos(pAngSide) * p.speed, p.pY + sin(pAngSide) * p.speed)) {
                    p.pX += cos(pAngSide) * p.speed;
                    p.pY += sin(pAngSide) * p.speed;
                }
            }
            if (k.d == 1) {
                pAngSide = p.pAng + (PI / 2);
                if (!checkCollision(p.pX + cos(pAngSide) * p.speed, p.pY + sin(pAngSide) * p.speed)) {
                    p.pX += cos(pAngSide) * p.speed;
                    p.pY += sin(pAngSide) * p.speed;
                }
            }
            if (k.e == 1) {
                for (int i = 0; i < numberOfDoors; i++) {
                    if (d[i].inRange == true) {
                        d[i].isOpened = true;
                        openDoor(i);
                    }
                }
            }
            if (k.space == 1 && g.isFired == false && g.ammo != 0) {
                g.isFired = true;
            }

            //actually drawing everything
            glClear(GL_COLOR_BUFFER_BIT);
            drawMap();
            drawPlayer();
            drawEnemy(numberOfEnemies, deltaTime);
            drawLevelBackground(levelSelect);
            drawRays();
            drawWeapon(1);
            drawItem(numberOfItems);
            drawHUD();

            //check if door is open so it can be closed
            for (int i = 0; i < numberOfDoors; i++) {
                if (d[i].inRange == true && d[i].isOpened == false) {
                    drawText("E to open", SCREEN_WIDTH * 0.25, SCREEN_WIDTH * 0.33, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
                }
                if (d[i].isOpened == true) {
                    openDoor(i);
                }
            }
            if (g.isFired == true) {
                fireGun(deltaTime);
            }
        }
        if (p.state == 1) { //when player dies
            glClear(GL_COLOR_BUFFER_BIT);
            drawMap();
            drawLevelBackground(levelSelect);
            drawRays();
            drawHUD();
            drawText("Press P to Retry", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
        }
        if (p.state == 2) { //when completed level
            levelInit = false;
            completeSelect = 0;
            gameState = 4;
        }

        if (k.p == 1) { //reset level button, active as long as level has not been completed and game is not paused
            if (p.state != 2) {
                initMap();
                initPlayer();
                initWeapon();
                initEnemies();
                initItems();
                initDoors();
                w.wallTexture = loadTexture("textures/walls/wall.png");
                drawWeapon(1);
                p.state = 0;
            }
        }
    }
    else if (gameState == 4) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawMap();
        drawLevelBackground(levelSelect);
        drawRays();
   
        glfwWaitEventsTimeout(0.5);
        drawLevelCompleteBackground(completeSelect);
        if (k.down == 1) {
            completeSelect += 1;
            if (completeSelect > 1) {
                completeSelect = 0;
            }
        }
        if (k.up == 1) {
            completeSelect -= 1;
            if (completeSelect < 0) {
                completeSelect = 1;
            }
        }

        if ((k.space == 1 || k.enter == 1) && completeSelect == 0) {
            gameState = 3;
        }
        else if ((k.space == 1 || k.enter == 1) && completeSelect == 1) {
            levelSelect = 1;
            gameState = 1;
        }
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) { //key bindings
    if (key == GLFW_KEY_W && action == GLFW_PRESS) k.w = 1; 
    if (key == GLFW_KEY_W && action == GLFW_RELEASE) k.w = 0;

    if (key == GLFW_KEY_A && action == GLFW_PRESS) k.a = 1;
    if (key == GLFW_KEY_A && action == GLFW_RELEASE) k.a = 0;

    if (key == GLFW_KEY_S && action == GLFW_PRESS) k.s = 1;
    if (key == GLFW_KEY_S && action == GLFW_RELEASE) k.s = 0;

    if (key == GLFW_KEY_D && action == GLFW_PRESS) k.d = 1;
    if (key == GLFW_KEY_D && action == GLFW_RELEASE) k.d = 0;

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) k.space = 1;
    if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE) k.space = 0;

    if (key == GLFW_KEY_E && action == GLFW_PRESS) k.e = 1;
    if (key == GLFW_KEY_E && action == GLFW_RELEASE) k.e = 0;

    if (key == GLFW_KEY_P && action == GLFW_PRESS) k.p = 1;
    if (key == GLFW_KEY_P && action == GLFW_RELEASE) k.p = 0;

    if (key == GLFW_KEY_UP && action == GLFW_PRESS) k.up = 1;
    if (key == GLFW_KEY_UP && action == GLFW_RELEASE) k.up = 0;

    if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) k.down = 1;
    if (key == GLFW_KEY_DOWN && action == GLFW_RELEASE) k.down = 0;

    if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) k.left = 1;
    if (key == GLFW_KEY_LEFT && action == GLFW_RELEASE) k.left = 0;

    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) k.right = 1;
    if (key == GLFW_KEY_RIGHT && action == GLFW_RELEASE) k.right = 0;

    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS) k.enter = 1;
    if (key == GLFW_KEY_ENTER && action == GLFW_RELEASE) k.enter = 0;

    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) k.esc = 1;
    if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE) k.esc = 0;
}

int main(void){

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "untitled FPS game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    init();
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        display();
    }

    glfwTerminate();
    return 0;
}