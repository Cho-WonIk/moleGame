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
extern int Respawn_delay; // 두더지 리스폰 시간
extern GLint GameTime; // 게임 플레이 시간

void PrintNum(float x, float y, GLint Num, std::string AddText, int length); // 숫자 출력 함수

void UI(float x, float y, GLint Score); // 전체 UI출력함수

void CreateGameMenu(); // 메뉴생성 함수