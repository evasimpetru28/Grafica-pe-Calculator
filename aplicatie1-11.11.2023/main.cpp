#include <GL/glut.h>

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

void cod_curs() {
    glPointSize(40.0);
    glBegin(GL_POINTS);
    for (int dist = 0, i = 1; i <= 3; i++)
    {
        dist += 40;
        glVertex2i(40 * i + dist, 40);
    }
    glEnd();
}

void aplicatie() {
    glColor3f(.5, .5, 0.0);
    glLineWidth(20.0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(300.0, 350.0);
    glVertex2f(200.0, 200.0);
    glVertex2f(300.0, 50.0);
    glVertex2f(300.0, 350.0);
    glEnd();

    glColor3f(1, .0, 0.0);
    glLineWidth(10.0);

    glBegin(GL_POLYGON);
    glVertex2f(300.0, 350.0);
    glVertex2f(200.0, 200.0);
    glVertex2f(300.0, 200.0);
    glEnd();

    cod_curs();

    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(1450, 450);
    glutCreateWindow("puncte");
    init();

    glutDisplayFunc(aplicatie);
    glutReshapeFunc(reshape);
    glutMainLoop();
}
