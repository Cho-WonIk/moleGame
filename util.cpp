#include "util.h"

int random()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(1, 9);
	return dis(gen);
}

void glBitmapText(float x, float y, float z, std::string text, void* font)
{
	
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}

std::string ZeroFill_Number(GLint Number)
{
	std::string text = std::to_string(Number);
	int len = text.length();
	for (int i = 0; i < 5 - len; i++)
	{
		text.insert(0, "0");
	}
	return text;
}
