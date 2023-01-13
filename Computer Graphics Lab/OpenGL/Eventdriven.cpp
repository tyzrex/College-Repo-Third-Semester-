#include <GL/glut.h>

int width = 800;
int height = 600;

int click_x = 0;
int click_y = 0;

int move_x = 0;
int move_y = 0;

void init_glut(int *argc, char **argv, int x, int y, int width, int height, const char *window_title) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);

	glutCreateWindow(window_title);
}

void init_ogl(float bg_r, float bg_g, float bg_b) {
	glClearColor(bg_r, bg_g, bg_b, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, width, 0.0, height);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glPointSize(10);

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(click_x, click_y);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
		glVertex2i(move_x, move_y);
	glEnd();

	glFinish();
}

void mouse(int button, int state, int x, int y) {
	click_x = x;
	click_y = height - y;
	glutPostRedisplay();
}

void mouse_move(int x, int y) {
	move_x = x;
	move_y = height - y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		case 'w':
			click_y += 10;
			break;
		case 'a':
			click_x -= 10;
			break;
		case 's':
			click_y -= 10;
			break;
		case 'd':
			click_x += 10;
			break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	init_glut(&argc, argv, 80, 80, width, height, "Event driven");
	init_ogl(1.0, 1.0, 1.0);

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(mouse_move);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
