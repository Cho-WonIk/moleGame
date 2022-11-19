#pragma once
#include "wonik.h"


void convertDeviceXYOpenGLXY(GLfloat* ox, GLfloat* oy)
{
	*ox = (GLfloat)(MouseX - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Width / 2.0));
	*oy = -(GLfloat)(MouseY - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0));
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
	GLfloat FeildSize = 4.0;
	GLfloat Distance = FeildSize / 3.0;

	GLfloat StartX = -3.5;
	GLfloat StartY = 2.0;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			DrawSquare( (3 * y + x + 1) == RandomNumber, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
		}
	}

	glFlush();
}


void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY)
{
	if (Button ==GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		glMatrixMode(GL_MODELVIEW);
		GLfloat Click_X = (GLfloat)(MouseX - (GLfloat)Width / 2.0)* (GLfloat)(1.0 / (GLfloat)(Width / 2.0));
		GLfloat Click_Y = -(GLfloat)(MouseY - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0));
		std::cout << Click_X << " " << Click_Y << std::endl;
		int x = -100;
		int y = -1;

		if (Click_X < 0.14) //범위 안인지 확인
		{
			if (Click_X >= -1.0) // 1행
			{
				x = 0;

				if (Click_X >= -0.6) // 2행
				{
					x = 1;

					if (Click_X >= -0.2) //3행
					{
						x = 2;
					}
				}
			}
		}
		
		if ((Click_Y >= 0.33 && Click_Y < 1.0)) // 1열인 경우
		{
			y = 0;
		}
		else if ((Click_Y >= -0.33 && Click_Y < 0.33)) // 2열인 경우
		{
			y = 1;
		}
		else if ((Click_Y >= -1.0 && Click_Y < -0.33)) // 3열인 경우
		{
			y = 2;
		}
		else
		{
			y = -1;
		}
		std::cout << 3 * y + x + 1 << std::endl;
	}
}