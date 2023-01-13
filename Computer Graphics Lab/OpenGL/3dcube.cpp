#include <GL/glut.h>

void init_glut(int *argc, char **argv, int x, int y, int width, int height, const char *window_title) {
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(x, y);
	glutInitWindowSize(width, height);

	glutCreateWindow(window_title);
}

void init_ogl(float bg_r, float bg_g, float bg_b) {
	glClearColor(bg_r, bg_g, bg_b, 1.0);
	glEnable(GL_DEPTH_TEST);
}

void face(GLfloat a[], GLfloat b[], GLfloat c[], GLfloat d[]) {
	glBegin(GL_POLYGON);
	{
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
		glVertex3fv(d);
	}
	glEnd();
}


void cube(GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[], GLfloat v4[], GLfloat v5[], GLfloat v6[], GLfloat v7[]) {
	glColor3f(1, 0, 0);
	face(v0, v1, v2, v3);
	glColor3f(0, 1, 0);
	face(v4, v5, v6, v7);
	glColor3f(0, 0, 1);
	face(v0, v3, v7, v4);
	glColor3f(0, 1, 1);
	face(v1, v2, v6, v5);
	glColor3f(1, 0, 1);
	face(v0, v1, v5, v4);
	glColor3f(1, 1, 0);
	face(v3, v2, v6, v7);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	GLfloat vertices[8][3] = {
		{-0.5,  0.5,  0.5 },
                { 0.5,  0.5,  0.5 },
		{ 0.5,  -0.5, 0.5 },
                { -0.5, -0.5, 0.5 },

		{ -0.5, 0.5,  -0.5},
                { 0.5,  0.5,  -0.5},
		{ 0.5,  -0.5, -0.5},
                { -0.5, -0.5, -0.5},
	};

	glLoadIdentity();
	glRotatef(-40, 1, 1, 0);
	cube(vertices[0], vertices[1], vertices[2], vertices[3], vertices[4],
	     vertices[5], vertices[6], vertices[7]);

	glutSwapBuffers();
}

int main(int argc, char **argv) {
	init_glut(&argc, argv, 80, 80, 800, 600, "3D");
	init_ogl(1.0, 1.0, 1.0);

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
