#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Util.h"
#include "bmp.h"

extern const int Width; // 가로 길이
extern const int Height; // 세로 길이
extern GLint Score; // 점수
extern GLint MolePosition; // 두더지 위치
extern GLint GameTime; // 게임플레이시간 계산

static bool is_GameStart = false;
static GLfloat MouseX, MouseY; //마우스 위치 - gl좌표계로 변환됨

static const GLfloat FeildSize = 4.0; // 게임판 크기
static const GLfloat Distance = FeildSize / 3.0; // 게임판 격자 간격
static const GLfloat StartX = -3.5; // 게임판을 그릴 시작위치 (왼쪽 위)
static const GLfloat StartY = 2.0; // 게임판을 그릴 시작위치 (왼쪽 위)
static bool can_add_score = true;	// 점수 중복 입력방지
static bool is_Mouse_Click = false; // 마우스 클릭 여부 체크

// 콜백함수
void PassiveMouseMotion(int x, int y); // 마우스에 망치 달기
void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // 마우스 클릭이벤트 발생시 망치를 기울이고 두더지를 잡았는지 확인
void Respawn(int time); // 두더지 재생성

void GameStart(int Respawn_delay);

// 마우스 커서
void hammer(); // 망치 오브젝트

// 게임판 그리는 함수
void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // 필드 격자 그리는 함수
void DrawGameField();											// 전체 게임판 그리는 함수

// 좌표변환 함수
void convertDeviceXYOpenGLXY(GLint X, GLint Y); // 윈도우 좌표계를 gl좌표계로 변환