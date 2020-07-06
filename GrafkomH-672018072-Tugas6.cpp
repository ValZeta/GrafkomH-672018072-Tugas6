#include <windows.h>
#include <stdlib.h>
#include <GL/freeglut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);
void myKeyboard(unsigned char key, int x, int y);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int w = 500, h = 500, z = 0;
int x1 = 0, y1 = 0, sudut = 0, z1 = 0;
float skalaX = 1, skalaY = 1, skalaZ = 1;

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("Valen Brata Pranaya - 672018072");
	init();
	glutDisplayFunc(tampil);
	glutReshapeFunc(ukuran);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(myKeyboard);

	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(0, 0, z);
	glRotatef(sudut, x1, y1, z1);
	glScalef(skalaX, skalaY, skalaZ);

	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glPushMatrix();

	//depan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glEnd();

	//jendela depan
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, -5.0, 10.001);
	glVertex3f(-9.0, 0.0, 10.001);
	glVertex3f(-4.0, 0.0, 10.001);
	glVertex3f(-4.0, -5.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, -5.0, 9.999);
	glVertex3f(-9.0, 0.0, 9.999);
	glVertex3f(-4.0, 0.0, 9.999);
	glVertex3f(-4.0, -5.0, 9.999);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(9.0, -5.0, 10.001);
	glVertex3f(9.0, 0.0, 10.001);
	glVertex3f(4.0, 0.0, 10.001);
	glVertex3f(4.0, -5.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(9.0, -5.0, 9.999);
	glVertex3f(9.0, 0.0, 9.999);
	glVertex3f(4.0, 0.0, 9.999);
	glVertex3f(4.0, -5.0, 9.999);
	glEnd();

	//pintu depan
	glBegin(GL_QUADS);
	glColor3f(0.2, 0.1, 0);
	glVertex3f(-2.5, -10.0, 10.001);
	glVertex3f(-2.5, 0.0, 10.001);
	glVertex3f(2.5, 0.0, 10.001);
	glVertex3f(2.5, -10.0, 10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.2, 0.1, 0);
	glVertex3f(-2.5, -10.0, 9.999);
	glVertex3f(-2.5, 0.0, 9.999);
	glVertex3f(2.5, 0.0, 9.999);
	glVertex3f(2.5, -10.0, 9.999);
	glEnd();

	//pegangan pintu
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-2.0, -5.5, 10.002);
	glVertex3f(-2.0, -5.0, 10.002);
	glVertex3f(-1.8, -5.0, 10.002);
	glVertex3f(-1.8, -5.5, 10.002);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-2.0, -5.5, 9.998);
	glVertex3f(-2.0, -5.0, 9.998);
	glVertex3f(-1.8, -5.0, 9.998);
	glVertex3f(-1.8, -5.5, 9.998);
	glEnd();

	//atap depan
	glBegin(GL_TRIANGLES);
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(0.0, 15.0, 10.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.1, 0);
	glVertex3f(-10.0, 5.0, 9.999);
	glVertex3f(10.0, 5.0, 9.999);
	glVertex3f(0.0, 15.0, 9.999);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glEnd();

	//jendela belakang
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, -5.0, -10.001);
	glVertex3f(-9.0, 0.0, -10.001);
	glVertex3f(-4.0, 0.0, -10.001);
	glVertex3f(-4.0, -5.0, -10.001);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(-9.0, -5.0, -9.999);
	glVertex3f(-9.0, 0.0, -9.999);
	glVertex3f(-4.0, 0.0, -9.999);
	glVertex3f(-4.0, -5.0, -9.999);
	glEnd();

	//atap belakang
	glBegin(GL_TRIANGLES);
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.2, 0.1, 0);
	glVertex3f(-10.0, 5.0, -9.999);
	glVertex3f(10.0, 5.0, -9.999);
	glVertex3f(0.0, 15.0, -9.999);
	glEnd();

	//kanan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glEnd();

	//kiri
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.6, 0.3);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glEnd();

	//genteng
	glBegin(GL_QUADS);
	glColor3f(0.8, 0.3, 0.3);
	glVertex3f(0.0, 15.0, 10.0);
	glVertex3f(10.0, 5.0, 10.0);
	glVertex3f(10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.3, 0.3);
	glVertex3f(0.0, 15.0, 10.0);
	glVertex3f(-10.0, 5.0, 10.0);
	glVertex3f(-10.0, 5.0, -10.0);
	glVertex3f(0.0, 15.0, -10.0);
	glEnd();

	//bawah
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glEnd();


	///FURNITUR

	//kursi
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(6.0, -9.0, 3);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(6.0, -9.0, 0);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(9.0, -9.0, 3);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(9.0, -9.0, 0);
	glScalef(3, 15, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(7, -8.0, 1.5);
	glScalef(40, 1, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(9, -6.0, 1.5);
	glScalef(1, 40, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//lemari
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(6.9, -5.8, -7.9);
	glScalef(60, 80, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(8, -6, -6);
	glScalef(4, 4, 4);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(7, -5.8, -5.9);
	glScalef(1, 80, 1);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0, 0);
	glTranslatef(6, -6, -6);
	glScalef(4, 4, 4);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//kasur
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0, 0.3, 0.5);
	glTranslatef(-6.9, -9.4, -4.7);
	glScalef(60, 10, 100);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 1);
	glTranslatef(-6.6, -8.5, -7.5);
	glScalef(30, 3, 20);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(1, 1, 0);
	glTranslatef(-6.9, -8.85, -3);
	glScalef(58, 2, 60);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//meja
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(-6.0, -8.5, 8);
	glScalef(3, 25, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(-6.0, -8.5, 5);
	glScalef(3, 25, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(-9.0, -8.5, 8);
	glScalef(3, 25, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.2, 0.1, 0);
	glTranslatef(-9.0, -8.5, 5);
	glScalef(3, 25, 3);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(-7.5, -7.1, 6.5);
	glScalef(40, 1, 40);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	//rak dinding
	glPushMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glColor3f(0.5, 0.3, 0);
	glTranslatef(-9.3, 0, 0);
	glScalef(10, 2, 80);
	glutSolidCube(0.1);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void idle() {
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
}

void mouseMotion(int x, int y) {
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();
	}
}

void myKeyboard(unsigned char key, int x, int y) {
	if (key == 'a') z += 5;
	else if (key == 'd') z -= 5;
}

void ukuran(int w1, int h1) {
	glViewport(0, 0, w1, h1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w1 / (float)h1, 1.0, 300.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}