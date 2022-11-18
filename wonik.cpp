#pragma once
#include "wonik.h"
#include "random.h"
void PassiveMouseMotion(int x, int y)
{
	MouseX = x;
	MouseY = y;
	//std::cout << x << "  " << y << std::endl;
	glutPostRedisplay();
}

void hammer()
{
	GLfloat x = (static_cast<GLfloat>(MouseX) / Width);
	GLfloat y = -(static_cast<GLfloat>(MouseY) / Height); //좌표 원점이 달라 -를 붙임

	//std::cout << x << "  " << y << std::endl;

	glTranslatef(x, y, 0.0);

	glPushMatrix();//망치 제작중
	glColor3f(1.0, 0.3, 0.3);

	glutSolidCube(0.2);

	//glTranslatef(0.5, 0.0, 0.0);
	//glutSolidCube(0.2);

	glPopMatrix();

}

void DrawSquare(int num, int RandomNumber, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	if (num == RandomNumber)
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(1.0, 0.0, 0.0);

	glRectf(x1, y1, x2, y2);
}

void DrawGameField(int RandomNumber)
{
	GLfloat FeildSize = 4.0;
	GLfloat Distance = FeildSize / 3.0;

	GLfloat StartX = -3.5;
	GLfloat StartY = 2.0;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			//glRectf(StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
			DrawSquare( 3* y + x + 1, RandomNumber, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
		}
	}

	glFlush();
}

