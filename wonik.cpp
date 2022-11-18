#pragma once
#include "wonik.h"

void PassiveMouseMotion(int x, int y)
{
	MouseX = x;
	MouseY = y;
	std::cout << x << "  " << y << std::endl;
	glutPostRedisplay();
}

void hammer()
{
	GLfloat x = (static_cast<GLfloat>(MouseX) / Width);
	GLfloat y = -(static_cast<GLfloat>(MouseY) / Height); //��ǥ ������ �޶� -�� ����

	std::cout << x << "  " << y << std::endl;

	glTranslatef(x, y, 0.0);

	glPushMatrix();//��ġ ������
	glColor3f(1.0, 0.3, 0.3);

	glutSolidCube(0.2);

	//glTranslatef(0.5, 0.0, 0.0);
	//glutSolidCube(0.2);

	glPopMatrix();

}

void DrawField()
{
	glColor3f(1.0, 0.0, 0.0);
	glRectf(-3.5, 1.5, -0.5, -1.5);
	glFlush();
}
