#include "UI.h"

void PrintNum(float x, float y, GLint Num, std::string AddText, int length)// 숫자 출력 함수
{
	glColor3f(0.0, 0.0, 0.0);							//색상 - 일단 검정
	glBitmapText(x, y, 0.0, AddText + ZeroFill_Number(Num, length)); // 숫자 표시
}

void UI(float x, float y, GLint Score) //전체 UI
{
	PrintNum(x, y, Score, "Score: ", 5); //점수 표시
	PrintNum(x, y + 0.4, (60000 - GameTime) / 1000, "Time Left: ", 0); // 남은 시간 표시
	glBitmapText(x, y + 0.8, 0.0, "START");
	PrintNum(x, y + 1.2, Respawn_delay, "Level : ", 0);
}

void MainMenu(int entryID) {
	switch (entryID)
	{
	case static_cast<int>(MainMenu::START):
		GameStart();
		break;
	case static_cast<int>(MainMenu::GameSpeed):
		
		break;
	case static_cast<int>(MainMenu::Exit):
		exit(0);
		break;
	}
}

void GameLevelMenu(int entryID) {
	switch (entryID)
	{
		case static_cast<int>(GameLevel::Level_1):
			Respawn_delay = 1000;
			break;
		case static_cast<int>(GameLevel::Level_2):
			Respawn_delay = 800;
			break;
		case static_cast<int>(GameLevel::Level_3):
			Respawn_delay = 500;
			break;
	}
}

void CreateGameMenu()
{
	GLint GameLevelMenuID = glutCreateMenu(GameLevelMenu);
	glutAddMenuEntry("Level 1", 1);
	glutAddMenuEntry("Level 2", 2);
	glutAddMenuEntry("Level 3", 3);

	GLint MainMenuID = glutCreateMenu(MainMenu);
	glutAddMenuEntry("START", 1);
	glutAddSubMenu("GameSpeed", GameLevelMenuID);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}