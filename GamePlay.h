#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Util.h"
#include "bmp.h"

extern const int Width; // ���� ����
extern const int Height; // ���� ����
extern GLint Score; // ����
extern GLint MolePosition; // �δ��� ��ġ
extern GLint GameTime; // �����÷��̽ð� ���

static bool is_GameStart = false;
static GLfloat MouseX, MouseY; //���콺 ��ġ - gl��ǥ��� ��ȯ��

static const GLfloat FeildSize = 4.0; // ������ ũ��
static const GLfloat Distance = FeildSize / 3.0; // ������ ���� ����
static const GLfloat StartX = -3.5; // �������� �׸� ������ġ (���� ��)
static const GLfloat StartY = 2.0; // �������� �׸� ������ġ (���� ��)
static bool can_add_score = true;	// ���� �ߺ� �Է¹���
static bool is_Mouse_Click = false; // ���콺 Ŭ�� ���� üũ

// �ݹ��Լ�
void PassiveMouseMotion(int x, int y); // ���콺�� ��ġ �ޱ�
void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // ���콺 Ŭ���̺�Ʈ �߻��� ��ġ�� ����̰� �δ����� ��Ҵ��� Ȯ��
void Respawn(int time); // �δ��� �����

void GameStart(int Respawn_delay);

// ���콺 Ŀ��
void hammer(); // ��ġ ������Ʈ

// ������ �׸��� �Լ�
void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // �ʵ� ���� �׸��� �Լ�
void DrawGameField();											// ��ü ������ �׸��� �Լ�

// ��ǥ��ȯ �Լ�
void convertDeviceXYOpenGLXY(GLint X, GLint Y); // ������ ��ǥ�踦 gl��ǥ��� ��ȯ