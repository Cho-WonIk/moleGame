#include "glText.h"

void glBitmapText(float x, float y, float z, char* string, void* font)
{
    char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}