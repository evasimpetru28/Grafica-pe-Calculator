#include <GL/freeglut.h>

int GAngle = 30;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();// Initializeaza sistemul de coordonate
    glRotated(GAngle, 1, 1, 1);//face o rotatie a unghiului in jurul vectorilor x, y, z

    glTranslated(0.2, 0.5, 0);
    glColor3f(1, 0, 0);
    glutWireTeapot(0.5);

    glTranslated(-0.2, -0.5, 0);
    glColor3f(1, 1, 0);
    glutWireCube(0.5);//cub schelet

    GAngle = GAngle + 1;
    glFlush();
}

void Timer(int extra) {
    glutPostRedisplay();//fereastra curenta este reafisata
    glutTimerFunc(30, Timer, 0);//seteaza timer-ul pentru fereastra curenta
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
//glutInitWindowSize(640, 480);
    glutCreateWindow("cub rotativ");
    glutDisplayFunc(display);
    glutTimerFunc(0, Timer, 0);
    glutMainLoop();
    return 0;
}