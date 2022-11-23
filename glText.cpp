#include "glText.h"

void glBitmapText(float x, float y, float z, std::string text, void* font)
{
    glRasterPos3f(x, y, z);
	for (int i = 0; i < text.length(); i++)
	{
		char x = text.at(i);
		glutBitmapCharacter(font, (int)x);
	}
}