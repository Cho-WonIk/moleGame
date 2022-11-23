#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <string>

void glBitmapText(float x, float y, float z, std::string text, void* font = GLUT_BITMAP_HELVETICA_18);