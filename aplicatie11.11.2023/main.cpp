#include <GL/glut.h>

void init()
{
    glClearColor(.0, .0, .0, 0.0);//stabileste culoarea de sters
// glShadeModel (GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    ////////////////////// CUSTOM TRIANGLES

    glColor3f(.0, 1.0, .0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0, 400.0);
    glVertex2f(200.0, 600.0);
    glVertex2f(0.0, 400.0);
    glEnd();

    glColor3f(1.0, .0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(200.0, 200.0);
    glVertex2f(0.0, 200.0);
    glEnd();

    glColor3f(0.1, .0, .6);
    glBegin(GL_POLYGON);
    glVertex2f(400.0, 200.0);
    glVertex2f(600.0, 200.0);
    glVertex2f(600.0, 0.0);
    glEnd();

    glColor3f(0.5, .0, .0);
    glBegin(GL_POLYGON);
    glVertex2f(400.0, 400.0);
    glVertex2f(400.0, 600.0);
    glVertex2f(600.0, 600.0);
    glEnd();

    glColor3f(0.0, .5, .3);
    glBegin(GL_POLYGON);
    glVertex2f(400.0, 400.0);
    glVertex2f(600.0, 400.0);
    glVertex2f(600.0, 600.0);
    glEnd();

    ////////////////////////// CENTER TRIANGLES

    glBegin(GL_POLYGON);
    glColor3f(0.2, 0.0, 0.0);
    glVertex2f(200.0, 200.0);
    glVertex2f(400.0, 200.0);
    glVertex2f(400.0, 400.0);
    glEnd();
    glFlush();

    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0, 400.0);
    glVertex2f(400.0, 400.0);
    glVertex2f(200.0, 200.0);
    glEnd();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(
            GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 10);
    glutCreateWindow("aplic 11.11.2023");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
