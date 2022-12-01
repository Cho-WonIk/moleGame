#include "UI.h"

int Respawn_delay = 1000; // 두더지 생성 시간 조절

void PrintNum(float x, float y, GLint Num, std::string AddText, int length) // 숫자 출력 함수
{
	glColor3f(0.0, 0.0, 0.0);												//색상 - 검정
	glBitmapText(x, y, 0.0, AddText + ZeroFill_Number(Num, length));		// 숫자 표시
}

void UI(float x, float y, GLint Score, GLint GameTime) //전체 UI
{
	glColor3f(1.0f, 0.0f, 0.0f);										//START 글자의 색상 - 빨간색
	glBitmapText(x, y + 1.2, 0.0, "START");								// START 글자 표시

	PrintNum(x, y + 0.8, Level, "Level : ", 0);							//게임 레벨 표시

	PrintNum(x, y + 0.4, (60000 - GameTime) / 1000, "Time Left: ", 0);  // 남은 시간 표시

	PrintNum(x, y, Score, "Score: ", 5);								//점수 표시
}

void MainMenu(int entryID) {
	switch (entryID)
	{
	case static_cast<int>(MainMenu::START):
		GameStart(Respawn_delay);
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
			Level = 1;
			break;
		case static_cast<int>(GameLevel::Level_2):
			Respawn_delay = 800;
			Level = 2;
			break;
		case static_cast<int>(GameLevel::Level_3):
			Respawn_delay = 500;
			Level = 3;
			break;
	}
}

void CreateGameMenu() // 마우스 우클릭 메뉴 생성
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