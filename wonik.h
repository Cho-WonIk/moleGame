#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void PassiveMouseMotion(int x, int y);

void hammer();

void DrawSquare(int num, int RandomNumber, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void DrawGameField(int RandomNumber);

extern const int DisplaySize;		 // 윈도우 사이즈 기본 단위
extern const int Width; // 가로 길이
extern const int Height; // 세로 길이

extern int MouseX, MouseY;