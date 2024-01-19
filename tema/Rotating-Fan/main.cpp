#include <GL/glut.h>

float rotationSpeed = 0.2f;
static float angle = 0.0f;

void drawBlade() {
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.5f);
    glVertex2f(-0.1f, 0.5f);
    glEnd();
}

void Timer(int value) {

    angle += rotationSpeed;
    if (angle > 360.0f) {
        angle -= 360.0f;
    }

    glutTimerFunc(10, Timer, 0);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+': // ceste viteza
            rotationSpeed += 0.5f;
            break;
        case '-': // scade viteza
            if (rotationSpeed > 0.5f) {
                rotationSpeed -= 0.5f;
            }
            break;
    }
}

void initGL() {
    glClearColor(0.5f, 0.0f, 0.7f, 0.6f);
}

// Functie care deseneaza 3 elice folosind triunghiur
// si le roteste, avand optiunea de creste si minimizare
// a vitezei folosind + si - de la tastatura
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < 4; ++i) {
        glPushMatrix();
        glRotatef(angle + i * 90, 0.0f, 0.0f, 1.0f);
        drawBlade();
        glPopMatrix();
    }

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rotating Fan: Simpetru Eva-Maria 208 ID");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    initGL();

    glutTimerFunc(0, Timer, 0);

    glutMainLoop();
    return 0;
}