#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "wonik.h"

	const int DisplaySize = 100;		 // 윈도우 사이즈 기본 단위
	const int Width = DisplaySize * 16; // 가로 길이
	const int Height = DisplaySize * 9; // 세로 길이


void MoleGame_Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	hammer();

	glutSwapBuffers();
}

void MoleReshape(int width, int height) {
	float ratio = 1.0 * width / height;

	glViewport(0, 0, width, height);                   //그냥 윈도우 크기대로 뷰포트 해줌

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();    //플래그 설정했다가 이벤트 루프 마지막에 디스플레이해라.
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // initilize 초기화
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutDisplayFunc(MoleGame_Display); // display이벤트 발생
	glutReshapeFunc(MoleReshape);
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutMainLoop();
	return 0;
}