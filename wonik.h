#pragma once
#include <iostream>
#include <tuple>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "random.h"

void PassiveMouseMotion(int x, int y);

void hammer();

void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void DrawGameField(int RandomNumber);

void convertDeviceXYOpenGLXY(GLint X, GLint Y); // 윈도우 좌표계를 gl좌표계로 변환

void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY);
void Respawn(int time);


extern const int Width; // 가로 길이
extern const int Height; // 세로 길이

extern GLfloat MouseX, MouseY;

extern const GLfloat FeildSize;
extern const GLfloat Distance;
extern const GLfloat StartX, StartY;