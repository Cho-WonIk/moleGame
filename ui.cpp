#include "UI.h"

bool is_GameStart = false;

void PrintNum(float x, float y, GLint Num, std::string AddText, int length)// 숫자 출력 함수
{
	glColor3f(0.0, 0.0, 0.0);							//색상 - 일단 검정
	glBitmapText(x, y, 0.0, AddText + ZeroFill_Number(Num, length)); // 숫자 표시
}

void UI(float x, float y, GLint Score) //전체 UI
{
	PrintNum(x, y, Score, "Score: ", 5); //점수 표시
	PrintNum(x, y + 0.4, (60000 - GameTime) / 1000, "Time Left: ", 0); // 남은 시간 표시
	glBitmapText(x, y + 0.8, 0.0, "START"); // 대충 이런식으로 작성해줘 매개변수는 수정해됨 일단 대충 작성한거야
}

void MainMenu(int entryID) {
	switch (entryID)
	{
	case 1: //START
		GameStart();
		break;
	case 2: //GameSpeed
		
		break;
	case 3: //Exit
		exit(0);
		break;
	}
}

void GameSpeedMenu(int entryID) {
	switch (entryID)
	{
		case 1: //Level 1
			Respawn_delay = 1000;
			break;
		case 2: //Level 2
			Respawn_delay = 800;
			break;
		case 3: //Level 3
			Respawn_delay = 500;
			break;
	}
}

void CreateGameMenu()
{
	GLint GameSpeedMenuID = glutCreateMenu(GameSpeedMenu);
	glutAddMenuEntry("Level 1", 1);
	glutAddMenuEntry("Level 2", 2);
	glutAddMenuEntry("Level 3", 3);

	GLint MainMenuID = glutCreateMenu(MainMenu);
	glutAddMenuEntry("START", 1);
	glutAddSubMenu("GameSpeed", GameSpeedMenuID);
	glutAddMenuEntry("exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}