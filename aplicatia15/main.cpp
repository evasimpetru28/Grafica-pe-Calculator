#include <math.h>
#include <GL/freeglut.h>

void Display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        glVertex2f(cos(2 * 3.14159 * i / 1000.0), sin(2 * 3.14159 * i / 1000.0));
    }
    glEnd();
    glFlush();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(0.0f, 0.75f);
    glVertex2f(-.5f, .25f);
    glVertex2f(.5f, .25f);
    glVertex2f(-.5f, -.5f);
    glVertex2f(.5f, -.5f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-.25f, .25f);
    glVertex2f(-.5f, -.25f);
    glVertex2f(.5f, -.25f);
    glVertex2f(.25f, .25f);

    glEnd();
    glFlush();

}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("Exemplu");

    glutDisplayFunc(Display);
    glutMainLoop();
}
