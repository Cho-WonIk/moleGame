#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void PassiveMouseMotion(int x, int y);

void hammer();

void DrawSquare(int num, int RandomNumber, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
void DrawGameField(int RandomNumber);

extern const int DisplaySize;		 // ������ ������ �⺻ ����
extern const int Width; // ���� ����
extern const int Height; // ���� ����

extern int MouseX, MouseY;