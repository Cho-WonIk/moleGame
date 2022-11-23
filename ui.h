#pragma once
#include <string>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "util.h"
#include "GamePlay.h"

extern int Respawn_delay;

void PrintScore(float x, float y, GLint Score);

void UI(float x, float y, GLint Score);

void CreateGameMenu();