#include <iostream>
#include <GL/glut.h>
#include <math.h>

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
//glPointSize(50.0);
    glShadeModel(GL_FLAT);
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(1, 0);
    glVertex2i(0, 0);
    glVertex2i(0, 1);
    glEnd();
    glPointSize(3.0);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; ++i) {
        glVertex3f(cos(2 * 3.14159 * i / 100.0) * 0.4, sin(2 * 3.14159 * i /
                                                           100.0) * 0.4, 0);
    }
    glEnd();
    glFlush();
}

void display2() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(3.0);
    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 100; ++i) {
        glVertex3f(cos(2 * 3.14159 * i / 100.0) * 0.2, sin(2 * 3.14159 * i /
                                                           100.0) * 0.2, 0);
    }
    glEnd();

    glPointSize(3.0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        glVertex3f(cos(2 * 3.14159 * i / 1000.0) * 0.8, sin(2 * 3.14159 * i /
                                                           1000.0) * 0.8, 0);
    }
    glEnd();

    glFlush();
}


void display3() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(3.0);
    glColor3f(1.0, .0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex3f(.5, .5, 0);
    glVertex3f(.5, -.5, 0);
    glVertex3f(-.5, -.5, 0);
    glEnd();

    glColor3f(1, 1, 0);
    glBegin(GL_POINTS);
    for (int i = 0; i < 1000; ++i) {
        glVertex3f(cos(2 * 3.14159 * i / 1000.0) * 0.7, sin(2 * 3.14159 * i /
                                                            1000.0) * 0.7, 0);
    }
    glEnd();

    glPointSize(50.0);
    glBegin(GL_POINTS);
    glVertex3f(-0.9,-0.9, 0);
    glEnd();

    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex3f(0,0, 0);
    glEnd();

    glColor3f(0,0,1);
    glPointSize(100.0);
    glBegin(GL_POINTS);
    glVertex3f(-0.8,0.8, 0);
    glEnd();

    glFlush();
}


int meniu_1, meniu_2, meniu_main;

void meniu_principal(int key) {
    if (key == 0) {
        exit(0);
    }
}

void callback_1(int key) {
    switch (key) {
        case 0:
            printf("Cerc 1\n");
            break;
        case 1:
            printf("Cerc 2\n");
            break;
    }
}

void callback_2(int key) {
    switch (key) {
        case 0:
            printf("Ati selectat dreptunghi 1\n");
            break;
        case 1:
            printf("Ati selectat dreptunghi 2\n");
            break;
    }
}

GLint x = 10;
GLint y = 20;
GLint WindowWidth = 400;
GLint WindowHight = 400;

void mouseHandler(int button, int state, int mouse_x, int mouse_y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        x = mouse_x;
        y = WindowHight - mouse_y;
        glColor3f(1, 0, 0);
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        printf("x=%d , y=%d \n", x, y);
        glEnd();
        glFlush();
//        glClear(GL_COLOR_BUFFER_BIT);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(400, 100);
    glutCreateWindow("aplicatii 11.11.2023");
    init();
    glutMouseFunc(mouseHandler);
    glutDisplayFunc(display);
//    glutDisplayFunc(display2);
//    glutDisplayFunc(display3);

    glutKeyboardFunc(OnKeyPress);

    meniu_1 = glutCreateMenu(callback_1);
    glutAddMenuEntry("cerc1", 0);
    glutAddMenuEntry("cerc2", 1);
    meniu_2 = glutCreateMenu(callback_2);
    glutAddMenuEntry("dreptunghi1", 0);
    glutAddMenuEntry("dreptunghi2", 1);
    meniu_main = glutCreateMenu(meniu_principal);
    glutAddSubMenu("cerc", meniu_1);
    glutAddSubMenu("patrat", meniu_2);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
    return 0;
}