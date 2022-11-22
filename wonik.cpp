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
	std::cout << MouseX << "  " << MouseY << std::endl;
	glutPostRedisplay();
}

void hammer()
{
	GLfloat x = (static_cast<GLfloat>(MouseX) / Width);
	GLfloat y = -(static_cast<GLfloat>(MouseY) / Height); //��ǥ ������ �޶� -�� ����

	//std::cout << x << "  " << y << std::endl;

	glTranslatef(x, y, 0.0);

	glPushMatrix();//��ġ ������
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

void DrawGameField(int MoleNumber)
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			DrawSquare( (3 * y + x + 1) == MoleNumber, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
		}
	}
	glFlush();
}

void is_Catch_Mole(GLint Button, GLint State, GLint mX, GLint mY)
{
	int NumpadX = -100;
	int NumpadY = -1;

	if (Button ==GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		glMatrixMode(GL_MODELVIEW);
		convertDeviceXYOpenGLXY(mX, mY);
		//std::cout << MouseX << " " << MouseY << std::endl;
		if (MouseX < (StartX + FeildSize)) //���� ������ Ȯ��
		{
			if (MouseX >= StartX) // 1��
			{
				NumpadX = 0;

				if (MouseX >= (StartX + Distance)) // 2��
				{
					NumpadX = 1;

					if (MouseX >= (StartX + 2 * Distance)) //3��
					{
						NumpadX = 2;
					}
				}
			}
		}
		
		if (MouseY > (StartY - FeildSize)) //���� ������ Ȯ��
		{
			if (MouseY <= StartY)	// 1��
			{
				NumpadY = 0;

				if (MouseY <= (StartY - Distance)) // 2��
				{
					NumpadY = 1;

					if (MouseY <= (StartY - 2 * Distance)) // 3��
					{
						NumpadY = 2;
					}
				}
			}
		}
		//std::cout << 3 * NumpadY + NumpadX + 1 << std::endl;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // �δ����� Ŭ���߰� ������ �Է��� �ƴ϶��
	{
		Score += 1;
		can_add_score = false; // ���콺 Ŭ���� �����Ƿ� ���� �Է� ��Ȱ��ȭ
		std::cout << Score << std::endl;
	}
}

void Respawn(int time)
{
	//std::cout << time << std::endl;
	MolePosition = random();
	GameTime += time;

	can_add_score = true; // �δ����� ������ �Ǿ����Ƿ� �����Է� Ȱ��ȭ

	//std::cout << GameTime << std::endl;
	if (GameTime < 1000 * 60) // �����÷��� Ÿ���� 60��
	{
		glutTimerFunc(time, Respawn, 1000);
	}
	glutPostRedisplay();
}