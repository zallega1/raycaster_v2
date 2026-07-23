#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <GLFW/glfw3.h>
#include "stb_image.h"

//loads images in using stb_image.h
GLuint loadTexture(const char* filename);

#endif
