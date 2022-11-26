#pragma once
#include <string>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "util.h"
#include "GamePlay.h"

enum class MainMenu {
	START = 1,
	GameSpeed,
	Exit
};

enum class GameLevel {
	Level_1 = 1,
	Level_2,
	Level_3
};
static int Respawn_delay = 1000; // �δ��� ���� �ð� ����

static int Level = 1;

void PrintNum(float x, float y, GLint Num, std::string AddText, int length); // ���� ��� �Լ�

void UI(float x, float y, GLint Score, GLint GameTime); // ��ü UI����Լ�

void CreateGameMenu(); // �޴����� �Լ�