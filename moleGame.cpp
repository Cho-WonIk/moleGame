#pragma once
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "wonik.h"
#include "random.h"

//ȭ�� ũ��� �����ũ���� 1/4
const int Width = GetSystemMetrics(SM_CXSCREEN) / 2; // ���� ����
const int Height = GetSystemMetrics(SM_CYSCREEN) / 2; // ���� ����

GLfloat MouseX, MouseY;

const GLfloat FeildSize = 4.0;
const GLfloat Distance = FeildSize / 3.0;
const GLfloat StartX = -3.5;
const GLfloat StartY = 2.0;

void MoleGame_Display() {
	glViewport(0, 0, Width, Height);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//hammer(); - �ϴ� ��Ȱ��ȭ
	DrawGameField(random());
	glutSwapBuffers();
}

void MoleReshape(int width, int height) {

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
	//glutPassiveMotionFunc(PassiveMouseMotion);
	glutMouseFunc(is_Catch_Mole);
	glutTimerFunc(1000, Respawn, 1000); // ������ ��ġ ��Ÿ��
	glutDisplayFunc(MoleGame_Display); // display�̺�Ʈ �߻�

	glutMainLoop();
	return 0;
}