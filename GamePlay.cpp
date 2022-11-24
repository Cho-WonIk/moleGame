#pragma once
#include "GamePlay.h"

GLfloat MouseX, MouseY; //���콺 ��ġ - gl��ǥ��� ��ȯ��
GLint GameTime = 0; // �����÷��̽ð� ���

const GLfloat FeildSize = 4.0; // ������ ũ��
const GLfloat Distance = FeildSize / 3.0; // ������ ���� ����
const GLfloat StartX = -3.5; // �������� �׸� ������ġ (���� ��)
const GLfloat StartY = 2.0; // �������� �׸� ������ġ (���� ��)

bool can_add_score = true;	// ���� �ߺ� �Է¹���
bool is_Mouse_Click = false;

int Respawn_delay = 1000; // �δ��� ���� �ð� ����

void convertDeviceXYOpenGLXY(GLint X, GLint Y) // ���콺 �ȼ����� gl��ǥ��� ��ȯ
{
	MouseX = (GLfloat)(X - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
	MouseY = -(GLfloat)(Y - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
}

void PassiveMouseMotion(int mX, int mY) // ���콺Ŭ���� ������ ���콺 ��ġ���� ��ȯ����
{
	convertDeviceXYOpenGLXY(mX, mY);
	//std::cout << MouseX << " " << MouseY << std::endl;
	//glutPostRedisplay();
}

void hammer()
{
	glPushMatrix();//��ġ
		
		glTranslatef(MouseX, MouseY, 0.0);

		if (is_Mouse_Click){
			glRotatef(90.0, 0.0, 0.0, 1.0); // ���콺�� Ŭ���Ȱ�� 90�� ȸ��
		}
		else{
			glRotatef(45.0, 0.0, 0.0, 1.0); // ���콺 Ŭ���� �ȵȰ�� 45�� ȸ��
		}
		glColor3f(0.0, 0.0, 0.0);
		glScalef(1.0, 2.5, 1.0);
		glutSolidCube(0.2); // ������
		
		glPushMatrix();
			glColor3f(1.0, 1.0, 0.0);
			glTranslatef(0.0, 0.1, 0.0);
			glScalef(2.9, 0.5, 1.0);
			glutSolidCube(0.2); // ��ġ �Ӹ�
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

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) // ���콺 ���� ��ư�� ������ ���
	{	
		is_Mouse_Click = true;
		//std::cout << is_Mouse_Click << std::endl;
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
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP) // ���콺 ���� ��ư�� �ȴ����� ��� ���콺�� Ŭ�� �ȵǾ��ٴ� ����� �˸���.
	{
		is_Mouse_Click = false;
		//std::cout << is_Mouse_Click << std::endl;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // �δ����� Ŭ���߰� ������ �Է��� �ƴ϶��
	{
		Score += 1;
		can_add_score = false; // ���콺 Ŭ���� �����Ƿ� ���� �Է� ��Ȱ��ȭ
		//std::cout << Score << std::endl;
	}
}

void GameStart()
{
	if (is_GameStart == false && (GameTime == 0))
	{
		Score = 0;
		Respawn(Respawn_delay);
	}
}

void Respawn(int time)
{
	//std::cout << time << std::endl;
	int tmp = random();
	if (tmp == MolePosition) // ������ ������ ���� ���� ���ٸ� �ٽ� �Լ� ����
	{
		tmp = random();
	}
	MolePosition = tmp;
	
	GameTime += time;

	can_add_score = true; // �δ����� ������ �Ǿ����Ƿ� �����Է� Ȱ��ȭ

	//std::cout << GameTime << std::endl;
	if (GameTime < 1000 * 60) // �����÷��� Ÿ���� 60��
	{
		glutTimerFunc(time, Respawn, time);
	}
	else// ���� ���� ���
	{
		is_GameStart = false;
		GameTime = 0;
	}
	glutPostRedisplay();
}