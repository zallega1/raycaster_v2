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

enum gameState {
    TITLE_SCREEN,
    LEVEL_SELECT,
    SETTINGS,
    GAME_START,
    LEVEL_COMPLETE
};

enum titleSelect {
    NONE = -1, //none is used by level and complete select as well
    START = 0,
    QUIT = 1
};

enum levelSelect {
    BACK,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3
};

enum completeSelect {
    RESTART,
    BACK_TO_SELECT
};

GLFWwindow* window;
enum gameState gameState; 
enum titleSelect titleSelect; 
enum levelSelect levelSelect;
enum completeSelect completeSelect;

void init() { //initialize the screen on program startup
    glClearColor(0.2, 0.2, 0.2, 0);
    glOrtho(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, -1, 1);
    loadFont();
    gameState = TITLE_SCREEN;
    titleSelect = NONE;
    levelSelect = NONE;
    completeSelect = NONE;
}

float deltaX; //for mouse controls
float lastTime, currentTime, deltaTime;
bool levelInit; //flag for game start

void display() { //display the graphics
    //needed to calculate speed of movement
    currentTime = glfwGetTime();
    deltaTime = currentTime - lastTime;
    lastTime = currentTime;

    if (gameState == TITLE_SCREEN) {
        glfwWaitEventsTimeout(0.5);
        drawTitleBackground(titleSelect);
        levelInit = false;
        if (k.down == 1) {
            titleSelect += 1;
            if (titleSelect > QUIT) {
                titleSelect = START;
            }
        }
        if (k.up == 1) {
            titleSelect -= 1;
            if (titleSelect < START) {
                titleSelect = QUIT;
            }
        }

        if ((k.space == 1 || k.enter == 1) && titleSelect == START) {
            levelSelect = LEVEL_1;
            gameState = LEVEL_SELECT;
        }
        else if (((k.space == 1 || k.enter == 1) && titleSelect == QUIT)) {
            glfwTerminate();
        }
    }
    else if (gameState == LEVEL_SELECT) {
        glfwWaitEventsTimeout(0.5);
        drawLevelSelectBackground(levelSelect);
        if ((k.space == 1 || k.enter == 1) && levelSelect == LEVEL_1) {
            gameState = GAME_START;
        }
        else if ((k.space == 1 || k.enter == 1) && levelSelect == BACK) {
            titleSelect = START;
            gameState = TITLE_SCREEN;
        }

        if (k.down == 1) {
            levelSelect += 1;
            glfwWaitEventsTimeout(0.5);
            if (levelSelect > LEVEL_3) {
                levelSelect = BACK;
            }
        }
        if (k.up == 1) {
            levelSelect -= 1;
            glfwWaitEventsTimeout(0.5);
            if (levelSelect < BACK) {
                levelSelect = LEVEL_3;
            }
        }
    }
    else if (gameState == SETTINGS) {
        //todo: settings menu
    }
    else if (gameState == GAME_START) {
        if (levelInit == false) {
            initMap();
            initPlayer();
            initWeapon();
            initEnemies();
            initItems();
            initDoors();
            drawWeapon(1);
            levelInit = true;
        }
        //what to draw when player is alive
        if (p.state == ALIVE) {
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
        if (p.state == DEAD) { //when player dies
            glClear(GL_COLOR_BUFFER_BIT);
            drawMap();
            drawLevelBackground(levelSelect);
            drawRays();
            drawHUD();
            drawText("Press P to Retry", SCREEN_WIDTH * 0.125, SCREEN_WIDTH * 0.2083, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT * 0.625);
        }
        if (p.state == COMPLETE) { //when completed level
            levelInit = false;
            completeSelect = RESTART;
            gameState = LEVEL_COMPLETE;
        }

        if (k.p == 1) { //reset level button, active as long as level has not been completed and game is not paused
            if (p.state != COMPLETE) {
                initMap();
                initPlayer();
                initWeapon();
                initEnemies();
                initItems();
                initDoors();
                drawWeapon(1);
                p.state = 0;
            }
        }

        if (k.esc == 1) { //exit level
            levelInit = false;
            levelSelect = LEVEL_1;
            gameState = LEVEL_SELECT;
        }
    }
    else if (gameState == LEVEL_COMPLETE) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawMap();
        drawLevelBackground(levelSelect);
        drawRays();
   
        glfwWaitEventsTimeout(0.5);
        drawLevelCompleteBackground(completeSelect);
        if (k.down == 1) {
            completeSelect += 1;
            if (completeSelect > BACK_TO_SELECT) {
                completeSelect = RESTART;
            }
        }
        if (k.up == 1) {
            completeSelect -= 1;
            if (completeSelect < RESTART) {
                completeSelect = BACK_TO_SELECT;
            }
        }

        if ((k.space == 1 || k.enter == 1) && completeSelect == RESTART) {
            gameState = GAME_START;
        }
        else if ((k.space == 1 || k.enter == 1) && completeSelect == BACK_TO_SELECT) {
            levelSelect = LEVEL_1;
            gameState = LEVEL_SELECT;
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

int main(){

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_FALSE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "untitled FPS game", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    init();

    while (!glfwWindowShouldClose(window))
    {
        display();
    }

    glfwTerminate();
    return 0;
}