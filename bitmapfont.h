#pragma once
#include <gl\gl.h>   
#include <gl\glu.h> 
#include <GL/glut.h>
#include "GL/freeglut.h"

void glutBitmapCharacter(void* font, int character);

void glRasterPos2f(GLfloat x, GLfloat y);
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);

void renderBitmapCharacter(float x, float y, float z, void* font, char* string)
{
    char* c;
    glRasterPos3f(x, y, z);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}