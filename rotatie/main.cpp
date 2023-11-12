#include <iostream>
#include <GL/glut.h>

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

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);// Cadran 1
    for (int i = 0; i < 20; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(1 - i / 20.0, i / 20.0, 0);
    } // Cadran 3
    glColor3f(1, 0.4, 1);
    for (int i = 0; i < 20; i++) {
        glVertex3f(0, 0, 0);
        glVertex3f(-1 + i / 20.0, -i / 20.0, 0);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Aplic 11.11.2023");
    glutKeyboardFunc(OnKeyPress);
    glutMouseFunc(OnMouseClick);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}