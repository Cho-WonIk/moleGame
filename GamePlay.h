#pragma once
#include <iostream>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "util.h"
#include "ui.h"

extern const int Width; // 가로 길이
extern const int Height; // 세로 길이
extern GLint Score; // 점수
extern GLint MolePosition; // 두더지 위치

void PassiveMouseMotion(int x, int y); // 마우스에 망치 달기

void hammer(); // 망치 오브젝트

void DrawSquare(bool is_Diglett, GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2); // 필드 격자 그리는 함수
void DrawGameField(int RandomNumber);											// 전체 게임판 그리는 함수

void convertDeviceXYOpenGLXY(GLint X, GLint Y); // 윈도우 좌표계를 gl좌표계로 변환

void is_Catch_Mole(GLint Button, GLint State, GLint MouseX, GLint MouseY); // 마우스 클릭이벤트 발생시 두더지 잡았는지 확인
void Respawn(int time); // 두더지 재생성