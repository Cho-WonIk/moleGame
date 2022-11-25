#pragma once
#include <iostream>
#include <random>
#include <string>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "bmp.h"

#define MAX_NO_TEXTURES 2

GLuint texture[MAX_NO_TEXTURES];

int random();// 1~9������ ������ ���� �����.
void glBitmapText(float x, float y, float z, std::string text, void* font = GLUT_BITMAP_HELVETICA_18);// string�� ��Ʈ���������� �ٲپ� ������ش�.
std::string ZeroFill_Number(GLint Number, int length);// length���̷� ���� �е��� ���ڸ� ��ȯ�ϴ�..

void Textureinit(void);