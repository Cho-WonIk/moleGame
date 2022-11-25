#pragma once
#include "Util.h"


int random() // 1~9������ ������ ���� �����.
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}

void glBitmapText(float x, float y, float z, std::string text, void* font) // string�� ��Ʈ���������� �ٲپ� ������ش�. �⺻ ��Ʈ �� ũ��: HELVETICA_18
{
	glColor3f(0.0f, 0.0f, 0.0f);
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}

std::string ZeroFill_Number(GLint Number, int length) // length���̷� ���� �е��� ���ڸ� ��ȯ�ϴ�.
{
	std::string text = std::to_string(Number);
	int len = text.length();
	for (int i = 0; i < length - len; i++)
	{
		text.insert(0, "0");
	}
	return text;
}

