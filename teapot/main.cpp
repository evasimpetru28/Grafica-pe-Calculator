#include <GL/freeglut.h>

void Display_my_pot() {
    static float alpha = 20;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.1, 0.9, 1.0);
    glLoadIdentity();
    glPopMatrix();
    glRotatef(alpha, 1.9, 0.6, 0.5);
    glutWireTeapot(0.3);
    glPushMatrix();
    glFlush();
    alpha = alpha + 0.1;
    glutPostRedisplay();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
//glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Teapot");
    glutDisplayFunc(Display_my_pot);
    glutMainLoop();
    return 0;

}