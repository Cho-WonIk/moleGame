#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void PassiveMouseMotion(int x, int y);

void hammer();

extern const int DisplaySize;		 // ������ ������ �⺻ ����
extern const int Width; // ���� ����
extern const int Height; // ���� ����

extern int MouseX, MouseY;