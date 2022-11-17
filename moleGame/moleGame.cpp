#include "GL/glut.h"

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin
	(GL_POLYGON);
	glVertex2f(-0.2f, -0.2f);
	glVertex2f(0.4f, -0.4f);
	glVertex2f(0.4f, 0.4f);
	glVertex2f(-0.2f, 0.2f);

	glEnd();
	glFinish();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv); // initilize 초기화
	glutCreateWindow
	("OpenGL");
	// 테스트
	//테스트1223
	glutDisplayFunc(display); // display이벤트 발생
	glutMainLoop();
	return 0;
}