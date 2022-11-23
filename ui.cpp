#include "ui.h"

void PrintScore(float x, float y, GLint Score)
{
	glColor3f(0.0, 0.0, 0.0);							//score ���� - �ϴ� ����
	glBitmapText(x, y, 0.0, "Score: " + ZeroFill_Number(Score)); // ����ǥ��
}

void UI(float x, float y, GLint Score) //��ü UI
{
	PrintScore(x, y, Score); //���� ǥ��
	glBitmapText(x, y + 0.8, 0.0, "START"); // ���� �̷�������
}