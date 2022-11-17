#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "wonik.h"

void MoleGame_Display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glutSwapBuffers();
}

int main(int argc, char** argv) {

	static int DisplaySize = 100;		 // ������ ������ �⺻ ����
	static int Width = DisplaySize * 16; // ���� ����
	static int Height = DisplaySize * 9; // ���� ����

	glutInit(&argc, argv); // initilize �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(MoleGame_Display); // display�̺�Ʈ �߻�
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutMainLoop();
	return 0;
}