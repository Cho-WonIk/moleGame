#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "mouse.h"

//ȭ�� ũ��� �����ũ���� 1/4
const int Width = GetSystemMetrics(SM_CXSCREEN) / 2; // ���� ����
const int Height = GetSystemMetrics(SM_CYSCREEN) / 2; // ���� ����

int MouseX, MouseY;

void MoleGame_Display() {
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//hammer(); - �ϴ� ��Ȱ��ȭ

	glutSwapBuffers();
}

void MoleReshape(int width, int height) {
	float ratio = 1.0 * width / height;

	glViewport(0, 0, width, height);                   //�׳� ������ ũ���� ����Ʈ ����

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();

	glOrtho(-2.0 * (GLfloat)width / (GLfloat)height, 2.0 * (GLfloat)width / (GLfloat)height, -2.0, 2.0, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // initilize �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("MoleGame");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glutReshapeFunc(MoleReshape);
	glutPassiveMotionFunc(PassiveMouseMotion);
	glutDisplayFunc(MoleGame_Display); // display�̺�Ʈ �߻�

	glutMainLoop();
	return 0;
}