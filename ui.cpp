#include "UI.h"

bool is_GameStart = false;

void PrintNum(float x, float y, GLint Num, std::string AddText, int length)// ���� ��� �Լ�
{
	glColor3f(0.0, 0.0, 0.0);							//���� - �ϴ� ����
	glBitmapText(x, y, 0.0, AddText + ZeroFill_Number(Num, length)); // ���� ǥ��
}

void UI(float x, float y, GLint Score) //��ü UI
{
	PrintNum(x, y, Score, "Score: ", 5); //���� ǥ��
	PrintNum(x, y + 0.4, (60000 - GameTime) / 1000, "Time Left: ", 0); // ���� �ð� ǥ��
	glBitmapText(x, y + 0.8, 0.0, "START"); // ���� �̷������� �ۼ����� �Ű������� �����ص� �ϴ� ���� �ۼ��Ѱž�
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