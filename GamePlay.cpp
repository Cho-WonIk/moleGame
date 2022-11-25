#pragma once
#include "GamePlay.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
void convertDeviceXYOpenGLXY(GLint X, GLint Y) // ���콺 �ȼ����� gl��ǥ��� ��ȯ
{
	MouseX = (GLfloat)(X - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
	MouseY = -(GLfloat)(Y - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
}

void PassiveMouseMotion(int mX, int mY) // ���콺Ŭ���� ������ ���콺 ��ġ���� ��ȯ����
{
	convertDeviceXYOpenGLXY(mX, mY);
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
	unsigned int texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// �ؽ�ó wrapping/filtering �ɼ� ����(���� ���ε��� �ؽ�ó ��ü�� ����)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// �ؽ�ó �ε� �� ����
	int width, height, nrChannels;
	unsigned char* data = stbi_load("EmptyHole.png", &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		//glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);

	if (is_Diglett)
	{
		glColor3f(0.0, 1.0, 0.0);

		glRectf(x1, y1, x2, y2);
	}
	else
	{
		glColor3f(1.0, 0.0, 0.0);
		glRectf(x1, y1, x2, y2);
	}
}

void DrawGameField()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			DrawSquare( (3 * y + x + 1) == MolePosition, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
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
		convertDeviceXYOpenGLXY(mX, mY);

		if (MouseX < (StartX + FeildSize)) //���� ������ Ȯ��
		{					
			if (MouseX >= StartX) // 1���� ���
			{							
				NumpadX = 0;

				if (MouseX >= (StartX + Distance)) // 2���� ���
				{		
					NumpadX = 1;

					if (MouseX >= (StartX + 2 * Distance))  //3���� ���
					{ 
						NumpadX = 2;
					}
				}
			}
		}
		
		if (MouseY > (StartY - FeildSize)) //���� ������ Ȯ��
		{				
			if (MouseY <= StartY) // 1��
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
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP && is_Mouse_Click) // ���콺 ���� ��ư�� ������ ���� ���콺 Ŭ�����¸� �ٲ۴�.
	{
		is_Mouse_Click = false;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // �δ����� Ŭ���߰� ���� �Է��� ������ �����϶�
	{
		Score += 1;
		can_add_score = false; // ���콺 Ŭ���� �����Ƿ� ���� �Է� ��Ȱ��ȭ
		//std::cout << Score << std::endl;
	}
}

void GameStart(int Respawn_delay)
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
	GameTime += time;		// �������� �ɶ� ���� �����÷��� �ð��� �߰�
	can_add_score = true; // �δ����� ������ �Ǿ����Ƿ� �����Է� Ȱ��ȭ

	if (GameTime < 1000 * 60) // �����÷��� Ÿ���� 60��
	{
		glutTimerFunc(time, Respawn, time);
	}
	else// ���� ���� ���
	{
		is_GameStart = false;
		MolePosition = -1;
		GameTime = 0;
	}
	glutPostRedisplay();
}