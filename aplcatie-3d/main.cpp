#include <GL/freeglut.h>

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);

    float nr = 10.0;

    // Cadran 1
    for (int i = 0; i < nr; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(1 - i / nr, i / nr, 0);
    }

    // Cadran 2
    glColor3f(.0, 1, .6);
    for (int i = 0; i <= nr; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(-1 + i / nr, i / nr, 0);
    }

    // Cadran 3
    glColor3f(1, 0.4, .4);
    for (int i = 0; i < nr; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(-1 + i / nr, -i / nr, 0);
    }

    // Cadran 4
    glColor3f(1, 1, 1);
    for (int i = 0; i <= nr; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(-(-1 + i / nr), -i / nr, 0);
    }
    glEnd();

    float pas = 5.0;

    for (float i = 0.0; i <= pas; i++) {
        glBegin(GL_LINE_LOOP);
        glColor3f(1 - i / pas, i / pas, 1);
        glVertex3f(1 - i / pas, 0, 0);
        glVertex3f(0, 1 - i / pas, 0);
        glVertex3f(-(1 - i / pas), 0, 0);
        glVertex3f(0, -(1 - i / pas), 0);
        glEnd();
    }

    glFlush();
}

void roteste_Y(int p_grade) {
    glRotatef(p_grade, .0, 1.0, .0);
    glutPostRedisplay();
}

void roteste_X(int p_grade) {
    glRotatef(p_grade, 1., 0., .0);
    glutPostRedisplay();
}

void OnKeyPress(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
    switch (key) {
        case 'q':
        case 'Q':
            roteste_Y(3);
            break;
        case 'w':
        case 'W':
            roteste_Y(-3);
            break;
        case 'a':
        case 'A':
            roteste_X(3);
            break;
        case 's':
        case 'S':
            roteste_X(-3);
            break;
    }
}

void OnMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        roteste_Y(20);
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        roteste_Y(-20);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);

    glutCreateWindow("laborator 11.11.2023");

    glutKeyboardFunc(OnKeyPress);
    glutMouseFunc(OnMouseClick);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}