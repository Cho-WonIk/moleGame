#pragma once
#include "mouse.h"

void PassiveMouseMotion(int x, int y)
{
	MouseX = x;
	MouseY = y;

	glutPostRedisplay();
}

void hammer()
{
	GLfloat x = (static_cast<GLfloat>(MouseX) / Width);
	GLfloat y = -(static_cast<GLfloat>(MouseY) / Height); //좌표 원점이 달라 -를 붙임

	std::cout << x << "  " << y << std::endl;

	glTranslatef( x, y, 0.0);

	glPushMatrix();//망치 제작중
	glColor3f(1.0, 0.3, 0.3);

	glutSolidCube(0.2);

	//glTranslatef(0.5, 0.0, 0.0);
	//glutSolidCube(0.2);
	
	glPopMatrix();
	
}