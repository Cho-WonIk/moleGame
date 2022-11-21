#pragma once
#include "wonik.h"


void convertDeviceXYOpenGLXY(GLint X, GLint Y)
{
	MouseX = (GLfloat)(X - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
	MouseY = -(GLfloat)(Y - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
}

void PassiveMouseMotion(int x, int y)
{
	//MouseX = x;
	//MouseY = y;
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

void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	if (is_Diglett)
		glColor3f(0.0, 1.0, 0.0);
	else
		glColor3f(1.0, 0.0, 0.0);

	glRectf(x1, y1, x2, y2);
}

void DrawGameField(int RandomNumber)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			DrawSquare( (3 * y + x + 1) == RandomNumber, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
		}
	}
	glFlush();
}

void is_Catch_Mole(GLint Button, GLint State, GLint mX, GLint mY)
{
	if (Button ==GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		glMatrixMode(GL_MODELVIEW);
		convertDeviceXYOpenGLXY(mX, mY);
		std::cout << MouseX << " " << MouseY << std::endl;

		int NumpadX = -100;
		int NumpadY = -1;

		if (MouseX < (StartX + FeildSize)) //범위 안인지 확인
		{
			if (MouseX >= StartX) // 1행
			{
				NumpadX = 0;

				if (MouseX >= (StartX + Distance)) // 2행
				{
					NumpadX = 1;

					if (MouseX >= (StartX + 2 * Distance)) //3행
					{
						NumpadX = 2;
					}
				}
			}
		}
		
		if (MouseY > (StartY - FeildSize)) //범위 안인지 확인
		{
			if (MouseY <= StartY)	// 1열
			{
				NumpadY = 0;

				if (MouseY <= (StartY - Distance)) // 2열
				{
					NumpadY = 1;

					if (MouseY <= (StartY - 2 * Distance)) // 3열
					{
						NumpadY = 2;
					}
				}
			}
		}
		
		std::cout << 3 * NumpadY + NumpadX + 1 << std::endl;
	}
}

void Respawn(int time)
{
	//std::cout << time << std::endl;
	glutPostRedisplay();
	glutTimerFunc(time, Respawn, 1000);
}