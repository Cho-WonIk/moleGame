#pragma once
#include "Util.h"


int random() // 1~9사이의 랜덤한 수를 만든다.
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}

void glBitmapText(float x, float y, float z, std::string text, void* font) // string을 비트맵형식으로 바꾸어 출력해준다. 기본 폰트 및 크기: HELVETICA_18
{
	glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}

std::string ZeroFill_Number(GLint Number, int length) // length길이로 제로 패딩한 숫자를 반환하다.
{
	std::string text = std::to_string(Number);
	int len = text.length();
	for (int i = 0; i < length - len; i++)
	{
		text.insert(0, "0");
	}
	return text;
}

