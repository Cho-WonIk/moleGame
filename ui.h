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
extern int Respawn_delay; // �δ��� ������ �ð�
extern GLint GameTime; // ���� �÷��� �ð�

void PrintNum(float x, float y, GLint Num, std::string AddText, int length); // ���� ��� �Լ�

void UI(float x, float y, GLint Score); // ��ü UI����Լ�

void CreateGameMenu(); // �޴����� �Լ�