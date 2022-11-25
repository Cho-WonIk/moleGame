#pragma once
#include <iostream>
#include <random>
#include <string>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void Texture(void);
int random();// 1~9사이의 랜덤한 수를 만든다.
void glBitmapText(float x, float y, float z, std::string text, void* font = GLUT_BITMAP_HELVETICA_18);// string을 비트맵형식으로 바꾸어 출력해준다.
std::string ZeroFill_Number(GLint Number, int length);// length길이로 제로 패딩한 숫자를 반환하다..