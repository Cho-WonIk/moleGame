#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "GamePlay.h"
#include "UI.h"
#include "bmp.h"

//화면 크기는 모니터크기의 1/4
const int Width = GetSystemMetrics(SM_CXSCREEN) / 2; // 가로 길이
const int Height = GetSystemMetrics(SM_CYSCREEN) / 2; // 세로 길이

GLint Score = 0; // 게임 점수
GLint MolePosition; // 두더지 위치
GLint GameTime = 0; // 게임플레이시간 계산

void MoleGame_Display() {
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	UI(2.0, -0.5, Score, GameTime);
	DrawGameField(); // 게임판 작성
	hammer(); // 마우스 커서
	glutSwapBuffers();
}

void MoleReshape(int width, int height) {

	glViewport(0, 0, width, height);
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
	glutDisplayFunc(MoleGame_Display);
	CreateGameMenu();

	glutMainLoop();
	return 0;
}