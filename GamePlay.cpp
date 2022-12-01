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
		return new AUX_RGBImageRec(szFilename);     //파일로부터 메모리로
	}
	return NULL;
}

int LoadGLTextures(const char* szFilePath, int index) {       //파일을 로드하고 텍스쳐로 변환
	int Status = FALSE;
	glClearColor(0.0, 0.0, 0.0, 0.0);
	memset(pTextureImage, 0, sizeof(void*) * 1);    //포인터를 널로

	if (pTextureImage[index] = LoadBMP(szFilePath)) {   //비트맵을 로드하고 오류확인
		Status = TRUE;                              //상태 플랙을 True로
		glGenTextures(1, &MyTextureObject[index]);      //텍스쳐 생성
		glBindTexture(GL_TEXTURE_2D, MyTextureObject[index]);
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
			pTextureImage[index]->sizeX, pTextureImage[index]->sizeY,
			0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[index]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glEnable(GL_TEXTURE_2D);
	}
	if (pTextureImage[index]) {                 //텍스쳐가 존재하면
		if (pTextureImage[index]->data) {       //텍스쳐 영상이 존재하면
			free(pTextureImage[index]->data);   //텍스쳐 영상공간 반납
		}
		free(pTextureImage[index]);             //텍스쳐 반납
	}
	return Status;
}

void convertDeviceXYOpenGLXY(GLint X, GLint Y) // 마우스 픽셀값을 gl좌표계로 변환
{
	MouseX = (GLfloat)(X - (GLfloat)Width / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
	MouseY = -(GLfloat)(Y - (GLfloat)Height / 2.0) * (GLfloat)(1.0 / (GLfloat)(Height / 2.0)) * 2;
}

void PassiveMouseMotion(int mX, int mY) // 마우스클릭이 없을때 마우스 위치값을 변환해줌
{
	convertDeviceXYOpenGLXY(mX, mY);
}

void hammer()
{
	glPushMatrix();//망치
	glTranslatef(MouseX, MouseY, 0.0);

	if (is_Mouse_Click) {
		glRotatef(90.0, 0.0, 0.0, 1.0); // 마우스가 클릭된경우 90도 회전
	}
	else {
		glRotatef(45.0, 0.0, 0.0, 1.0); // 마우스 클릭이 안된경우 45도 회전
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
	glTexCoord2f(0.0f, 0.0f); glVertex3f(x1, y2, -1.0f);			//좌측 하단
	glTexCoord2f(1.0f, 0.0f); glVertex3f(x2, y2, -1.0f);			//우측 하단
	glTexCoord2f(1.0f, 1.0f); glVertex3f(x2, y1, -1.0f);			//우측 상단
	glTexCoord2f(0.0f, 1.0f); glVertex3f(x1, y1, -1.0f);	//좌측 상단
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

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) // 마우스 왼쪽 버튼이 눌렸을 경우
	{
		is_Mouse_Click = true;
		convertDeviceXYOpenGLXY(mX, mY);

		if (MouseX < (StartX + FeildSize)) //범위 안인지 확인
		{
			if (MouseX >= StartX) // 1행인 경우
			{
				NumpadX = 0;

				if (MouseX >= (StartX + Distance)) // 2행인 경우
				{
					NumpadX = 1;

					if (MouseX >= (StartX + 2 * Distance))  //3행인 경우
					{
						NumpadX = 2;
					}
				}
			}
		}

		if (MouseY > (StartY - FeildSize)) //범위 안인지 확인
		{
			if (MouseY <= StartY) // 1열
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

		if ((MouseX >= 2.0 && MouseX <= 2.5) && (MouseY >= 0.7 && MouseY <= 0.8)) //start버튼을 누른 경우
		{
			GameStart(Respawn_delay);
		}
	}
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP && is_Mouse_Click) // 마우스 왼쪽 버튼을 때면 마우스 클릭상태를 바꾼다.
	{
		is_Mouse_Click = false;
	}
	if ((MolePosition == (3 * NumpadY + NumpadX + 1)) && can_add_score) // 두더지를 클릭했고 점수 입력이 가능한 상태일때
	{
		Score += 1;
		can_add_score = false; // 점수를 입력했으므로 점수 입력 비활성화
		PlaySound("MP_Blop.wav", 0, SND_FILENAME | SND_ASYNC); // 두더지를 클릭해서 잡았을 시 소리 재생
		//std::cout << Score << std::endl;
	}
}

void GameStart(int Respawn_delay)
{
	if (is_GameStart == false) // 게임 시작 중복 실행 방지
	{
		is_GameStart = true; // 게임이 실행되었으므로 true로 바꿈
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
	if (tmp == MolePosition) // 생성된 난수가 이전 값과 같다면 다시 함수 실행
	{
		tmp = random();
	}
	MolePosition = tmp;
	GameTime += time;		// 리스폰이 될때 마다 게임플레이 시간을 추가
	can_add_score = true; // 두더지가 리스폰 되었으므로 점수입력 활성화

	if (GameTime < 1000 * 60) // 게임플레이 타임은 60초
	{
		glutTimerFunc(time, Respawn, time);
	}
	else// 게임 끝난 경우
	{
		is_GameStart = false;
		MolePosition = -1;
		//GameTime = 0;
	}
	glutPostRedisplay();
}