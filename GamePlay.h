#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Util.h"
#include "UI.h"

extern const int Width; // ���� ����
extern const int Height; // ���� ����
extern GLint Score; // ����
extern GLint MolePosition; // �δ��� ��ġ

// �ݹ��Լ�
void PassiveMouseMotion(int x, int y); // ���콺�� ��ġ �ޱ�
void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // ���콺 Ŭ���̺�Ʈ �߻��� ��ġ�� ����̰� �δ����� ��Ҵ��� Ȯ��
void Respawn(int time); // �δ��� �����
// ���콺 Ŀ��
void hammer(); // ��ġ ������Ʈ
// ������ �׸��� �Լ�
void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // �ʵ� ���� �׸��� �Լ�
void DrawGameField(int RandomNumber);											// ��ü ������ �׸��� �Լ�
// ��ǥ��ȯ �Լ�
void convertDeviceXYOpenGLXY(GLint X, GLint Y); // ������ ��ǥ�踦 gl��ǥ��� ��ȯ