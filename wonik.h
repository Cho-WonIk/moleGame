#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "random.h"

extern const int Width; // ���� ����
extern const int Height; // ���� ����

extern GLfloat MouseX, MouseY; //���콺 ��ġ - gl��ǥ��� ��ȯ��

extern GLint MolePosition, Score; // �δ����� ��ġ, ����

extern const GLfloat FeildSize; // ������ ũ��
extern const GLfloat Distance; // ������ ���� ����

extern const GLfloat StartX, StartY; // �������� �׸� ������ġ (���� ��)

extern GLint GameTime;

extern bool can_add_score;	// ���� �ߺ� �Է¹���

void PassiveMouseMotion(int x, int y); // ���콺�� ��ġ �ޱ�

void hammer(); // ��ġ ������Ʈ

void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // �ʵ� ���� �׸��� �Լ�
void DrawGameField(int RandomNumber);											// ��ü ������ �׸��� �Լ�

void convertDeviceXYOpenGLXY(GLint X, GLint Y); // ������ ��ǥ�踦 gl��ǥ��� ��ȯ

void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // ���콺 Ŭ���̺�Ʈ �߻��� �δ��� ��Ҵ��� Ȯ��
void Respawn(int time); // �δ��� �����