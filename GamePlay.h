#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Util.h"

extern const int Width; // ���� ����
extern const int Height; // ���� ����
extern GLint Score; // ����
extern GLint MolePosition; // �δ��� ��ġ

static bool is_GameStart = false;
static GLfloat MouseX, MouseY; //���콺 ��ġ - gl��ǥ��� ��ȯ��
static GLint GameTime = 0; // �����÷��̽ð� ���

static const GLfloat FeildSize = 4.0; // ������ ũ��
static const GLfloat Distance = FeildSize / 3.0; // ������ ���� ����
static const GLfloat StartX = -3.5; // �������� �׸� ������ġ (���� ��)
static const GLfloat StartY = 2.0; // �������� �׸� ������ġ (���� ��)

static bool can_add_score = true;	// ���� �ߺ� �Է¹���
static bool is_Mouse_Click = false;

static int Respawn_delay = 1000; // �δ��� ���� �ð� ����

// �ݹ��Լ�
void PassiveMouseMotion(int x, int y); // ���콺�� ��ġ �ޱ�
void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // ���콺 Ŭ���̺�Ʈ �߻��� ��ġ�� ����̰� �δ����� ��Ҵ��� Ȯ��
void Respawn(int time); // �δ��� �����

void GameStart();

// ���콺 Ŀ��
void hammer(); // ��ġ ������Ʈ

// ������ �׸��� �Լ�
void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // �ʵ� ���� �׸��� �Լ�
void DrawGameField(int RandomNumber);											// ��ü ������ �׸��� �Լ�

// ��ǥ��ȯ �Լ�
void convertDeviceXYOpenGLXY(GLint X, GLint Y); // ������ ��ǥ�踦 gl��ǥ��� ��ȯ