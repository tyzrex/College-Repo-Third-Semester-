#include <GL/glut.h>

void init(int *argc, char **argv) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.3, 0.2, 0.1);
		glVertex3f(0.5, 0.2, 0.1);
		glVertex3f(0.5, 0.5, 0.1);
	}
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	{
		glVertex3f(0.3, 0.4, 0.0);
		glVertex3f(0.6, 0.4, 0.0);
		glVertex3f(0.6, 0.5, 0.0);
	}
	glEnd();

	glFinish();
}

int main(int argc, char **argv) {
	init(&argc, argv);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
