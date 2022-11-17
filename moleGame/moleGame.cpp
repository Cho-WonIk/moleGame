#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "wonik.h"

	const int DisplaySize = 100;		 // ������ ������ �⺻ ����
	const int Width = DisplaySize * 16; // ���� ����
	const int Height = DisplaySize * 9; // ���� ����


void MoleGame_Display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	hammer();

	glutSwapBuffers();
}

void MoleReshape(int width, int height) {
	float ratio = 1.0 * width / height;

	glViewport(0, 0, width, height);                   //�׳� ������ ũ���� ����Ʈ ����

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();    //�÷��� �����ߴٰ� �̺�Ʈ ���� �������� ���÷����ض�.
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // initilize �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutDisplayFunc(MoleGame_Display); // display�̺�Ʈ �߻�
	glutReshapeFunc(MoleReshape);
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutMainLoop();
	return 0;
}