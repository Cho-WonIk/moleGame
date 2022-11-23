#pragma once
#include "GamePlay.h"

GLfloat MouseX, MouseY; //마우스 위치 - gl좌표계로 변환됨
GLint GameTime = 0; // 게임플레이시간 계산

const GLfloat FeildSize = 4.0; // 게임판 크기
const GLfloat Distance = FeildSize / 3.0; // 게임판 격자 간격
const GLfloat StartX = -3.5; // 게임판을 그릴 시작위치 (왼쪽 위)
const GLfloat StartY = 2.0; // 게임판을 그릴 시작위치 (왼쪽 위)

bool can_add_score = true;	// 점수 중복 입력방지
bool is_Mouse_Click = false;

void convertDeviceXYOpenGLXY(GLint X, GLint Y)
{
	MouseX = (GLfloat)(X - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
	MouseY = -(GLfloat)(Y - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
}

void PassiveMouseMotion(int mX, int mY)
{
	convertDeviceXYOpenGLXY(mX, mY);
	//std::cout << MouseX << " " << MouseY << std::endl;
	//glutPostRedisplay();
}

void hammer()
{
	glPushMatrix();//망치
		
		glTranslatef(MouseX, MouseY, 0.0);

		if (is_Mouse_Click)
		{
			glRotatef(90.0, 0.0, 0.0, 1.0);
		}
		else
		{
			glRotatef(45.0, 0.0, 0.0, 1.0);
		}
		glColor3f(0.0, 0.0, 0.0);
		glScalef(1.0, 2.5, 1.0);
		glutSolidCube(0.2); // 손잡이
		
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(0.0, 0.1, 0.0);
			glScalef(2.9, 0.5, 1.0);
			glutSolidCube(0.2); // 망치 머리
		glPopMatrix();
	glPopMatrix();
	glutPostRedisplay();
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

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{	
		is_Mouse_Click = true;
		//std::cout << is_Mouse_Click << std::endl;
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
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP)
	{
		is_Mouse_Click = false;
		//std::cout << is_Mouse_Click << std::endl;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // 두더지를 클릭했고 여러번 입력이 아니라면
	{
		Score += 1;
		can_add_score = false; // 마우스 클릭을 했으므로 점수 입력 비활성화
		//std::cout << Score << std::endl;
	}
}

void Respawn(int time)
{
	//std::cout << time << std::endl;
	int tmp = random();
	if (tmp == MolePosition) // 생성된 난수가 이전 값과 같다면 다시 함수 실행
	{
		tmp = random();
	}
	MolePosition = tmp;
	
	GameTime += time;

	can_add_score = true; // 두더지가 리스폰 되었으므로 점수입력 활성화

	//std::cout << GameTime << std::endl;
	if (GameTime < 1000 * 60) // 게임플레이 타임은 60초
	{
		glutTimerFunc(time, Respawn, time);
	}
	glutPostRedisplay();
}