#pragma once
#include "GamePlay.h"
#include "bmp.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

unsigned int MyTextureObject[2];
AUX_RGBImageRec* pTextureImage[2];

AUX_RGBImageRec* LoadBMP(const char* szFilename) {
	FILE* pFile = NULL;
	if (!szFilename) {
		return NULL;
	}
	fopen_s(&pFile, szFilename, "r");
	if (pFile) {
		fclose(pFile);
		return new AUX_RGBImageRec(szFilename);     //���Ϸκ��� �޸𸮷�
	}
	return NULL;
}

int LoadGLTextures(const char* szFilePath, int index) {       //������ �ε��ϰ� �ؽ��ķ� ��ȯ
	int Status = FALSE;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	memset(pTextureImage, 0, sizeof(void*) * 1);    //�����͸� �η�

	if (pTextureImage[index] = LoadBMP(szFilePath)) {   //��Ʈ���� �ε��ϰ� ����Ȯ��
		Status = TRUE;                              //���� �÷��� True��
		glGenTextures(1, &MyTextureObject[index]);      //�ؽ��� ����
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[index]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[index]->sizeX, pTextureImage[index]->sizeY,
			0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[index]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
	}
	if (pTextureImage[index]) {                 //�ؽ��İ� �����ϸ�
		if (pTextureImage[index]->data) {       //�ؽ��� ������ �����ϸ�
			free(pTextureImage[index]->data);   //�ؽ��� ������� �ݳ�
		}
		free(pTextureImage[index]);             //�ؽ��� �ݳ�
	}
	return Status;
}

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

	if (is_Mouse_Click) {
		glRotatef(90.0, 0.0, 0.0, 1.0); // ���콺�� Ŭ���Ȱ�� 90�� ȸ��
	}
	else {
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
	glColor4f(1.0, 1.0, 1.0, 0.0);
	if (is_Diglett)
	{
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[1]);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
	}
	glBegin(GL_POLYGON);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, y2, -1.0f);			//���� �ϴ�
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x2, y2, -1.0f);			//���� �ϴ�
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x2, y1, -1.0f);			//���� ���
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x1, y1, -1.0f);	//���� ���
	glEnd();
}

void DrawGameField()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			DrawSquare((3 * y + x + 1) == MolePosition, StartX + (Distance * x), StartY - (Distance * y), StartX + (Distance * (x + 1)), StartY - (Distance * (y + 1)));
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

		if ((MouseX >= 2.0 && MouseX <= 2.5) && (MouseY >= 0.7 && MouseY <= 0.8)) //start��ư�� ���� ���
		{
			GameStart(Respawn_delay);
		}
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP && is_Mouse_Click) // ���콺 ���� ��ư�� ���� ���콺 Ŭ�����¸� �ٲ۴�.
	{
		is_Mouse_Click = false;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // �δ����� Ŭ���߰� ���� �Է��� ������ �����϶�
	{
		Score += 1;
		can_add_score = false; // ������ �Է������Ƿ� ���� �Է� ��Ȱ��ȭ
		PlaySound("MP_Blop.wav", 0, SND_FILENAME | SND_ASYNC); // �δ����� Ŭ���ؼ� ����� �� �Ҹ� ���
		//std::cout << Score << std::endl;
	}
}

void GameStart(int Respawn_delay)
{
	if (is_GameStart == false) // ���� ���� �ߺ� ���� ����
	{
		is_GameStart = true; // ������ ����Ǿ����Ƿ� true�� �ٲ�
		Score = 0;
		GameTime = 0;
		Respawn(Respawn_delay);

		LoadGLTextures("Emptyhole.bmp", 0);
		LoadGLTextures("Molehole.bmp", 1);
		glEnable(GL_TEXTURE_2D);
		glShadeModel(GL_SMOOTH);
		glClearDepth(1.0);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
	}
}

void Respawn(int time)
{
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
		//GameTime = 0;
	}
	glutPostRedisplay();
}