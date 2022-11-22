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
		//std::cout << 3 * NumpadY + NumpadX + 1 << std::endl;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // 두더지를 클릭했고 여러번 입력이 아니라면
	{
		Score += 1;
		can_add_score = false; // 마우스 클릭을 했으므로 점수 입력 비활성화
		std::cout << Score << std::endl;
	}
}

void Respawn(int time)
{
	//std::cout << time << std::endl;
	MolePosition = random();
	GameTime += time;

	can_add_score = true; // 두더지가 리스폰 되었으므로 점수입력 활성화

	//std::cout << GameTime << std::endl;
	if (GameTime < 1000 * 60) // 게임플레이 타임은 60초
	{
		glutTimerFunc(time, Respawn, 1000);
	}
	glutPostRedisplay();
}