#pragma once
#include "wonik.h"

void PassiveMouseMotion(int x, int y)
{
	std::cout << x << y << std::endl;
	MouseX = x;
	MouseY = y;
}

void hammer()
{
	glTranslatef(MouseX / Width, MouseY / Height, 0.0);

	glPushMatrix();//¸ÁÄ¡ Á¦ÀÛÁß
	glColor3f(1.0, 0.3, 0.3);

	glutSolidCube(0.2);

	glTranslatef(0.5, 0.0, 0.0);
	glutSolidCube(0.2);

	glTranslatef(-1, 0.0, 0.0);
	glutSolidCube(0.2);

	glTranslatef(0.5, -0.5, 0.0);
	glutSolidCube(0.2);

	glTranslatef(0.0, -0.5, 0.0);
	glutSolidCube(0.2);
	glPopMatrix();
	
}