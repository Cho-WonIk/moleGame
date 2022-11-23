#pragma once
#include <iostream>
#include <random>
#include <string>
#include <format>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

int random();
void glBitmapText(float x, float y, float z, std::string text, void* font = GLUT_BITMAP_HELVETICA_18);
std::string ZeroFill_Number(GLint Number);