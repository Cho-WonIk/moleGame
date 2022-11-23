#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "GamePlay.h"
#include "util.h"
#include "ui.h"

//화면 크기는 모니터크기의 1/4
const int Width = GetSystemMetrics(SM_CXSCREEN) / 2; // 가로 길이
const int Height = GetSystemMetrics(SM_CYSCREEN) / 2; // 세로 길이

GLint Score = 0; // 게임 점수
GLint MolePosition; // 두더지 위치

void MoleGame_Display() {
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//hammer(); - 일단 비활성화
	UI(2.0, -0.5, Score);
	DrawGameField(MolePosition); // 게임판 작성

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

	int Respawn_delay = 800; // 두더지 생성 시간 조절

	glutInit(&argc, argv); // initilize 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutReshapeFunc(MoleReshape);
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutMouseFunc(is_Catch_Mole);
	glutTimerFunc(Respawn_delay, Respawn, Respawn_delay); // 두더지 위치 쿨타임
	glutDisplayFunc(MoleGame_Display); // display이벤트 발생

	glutMainLoop();
	return 0;
}