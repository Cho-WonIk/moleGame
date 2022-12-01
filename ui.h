#pragma once
#include <string>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "util.h"
#include "GamePlay.h"

enum class MainMenu { // 우클릭 메인 메뉴의 entry번호
	START = 1,
	GameSpeed,  //2
	Exit		//3
};

enum class GameLevel { // 게임 레벨 단계 
	Level_1 = 1,	//1
	Level_2,		//2
	Level_3			//3
};


static int Level = 1;

void PrintNum(float x, float y, GLint Num, std::string AddText, int length); // 숫자 출력 함수

void UI(float x, float y, GLint Score, GLint GameTime); // 전체 UI출력함수

void CreateGameMenu(); // 메뉴생성 함수