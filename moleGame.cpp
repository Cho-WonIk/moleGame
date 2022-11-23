#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "wonik.h"
#include "util.h"

//화면 크기는 모니터크기의 1/4
const int Width = GetSystemMetrics(SM_CXSCREEN) / 2; // 가로 길이
const int Height = GetSystemMetrics(SM_CYSCREEN) / 2; // 세로 길이

GLfloat MouseX, MouseY; //마우스 위치 - gl좌표계로 변환됨

const GLfloat FeildSize = 4.0; // 게임판 크기
const GLfloat Distance = FeildSize / 3.0; // 게임판 격자 간격
const GLfloat StartX = -3.5; // 게임판을 그릴 시작위치 (왼쪽 위)
const GLfloat StartY = 2.0; // 게임판을 그릴 시작위치 (왼쪽 위)

bool can_add_score = true;	// 점수 중복 입력방지
GLint GameTime = 0; // 게임플레이시간 계산
GLint Score = 0; // 게임 점수
GLint MolePosition; // 두더지 위치

void MoleGame_Display() {
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//hammer(); - 일단 비활성화
	glBitmapText(2.0, -0.5, 0.0, ZeroFill_Number(Score));
	DrawGameField(MolePosition);
	glutSwapBuffers();
}

void MoleReshape(int width, int height) {

	glViewport(0, 0, width, height);                   //그냥 윈도우 크기대로 뷰포트 해줌
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // initilize 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutReshapeFunc(MoleReshape);
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutMouseFunc(is_Catch_Mole);
	glutTimerFunc(1000, Respawn, 1000); // 두더지 위치 쿨타임
	glutDisplayFunc(MoleGame_Display); // display이벤트 발생

	glutMainLoop();
	return 0;
}