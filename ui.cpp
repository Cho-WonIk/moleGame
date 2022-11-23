#include "ui.h"

void PrintScore(float x, float y, GLint Score)
{
	glColor3f(0.0, 0.0, 0.0);							//score 색상 - 일단 검정
	glBitmapText(x, y, 0.0, "Score: " + ZeroFill_Number(Score)); // 점수표시
}

void UI(float x, float y, GLint Score) //전체 UI
{
	PrintScore(x, y, Score); //점수 표시
	glBitmapText(x, y + 0.8, 0.0, "START"); // 대충 이런식으로
}