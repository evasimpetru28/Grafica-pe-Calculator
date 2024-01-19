#include <GL/glut.h>
#include <cmath>

float angle = 3.14159 / 4;
float pendulumLength = 1.0;
float gravitationalAcceleration = 9.81;
float timeStep = 0.01;
float angularVelocity = 0.0;


void Timer(int value) {
    // Calcul pentru acceleratia unghiulara (fizica simplificata a unui pendul)
    float angularAcceleration = -(gravitationalAcceleration / pendulumLength) * sin(angle);

    angularVelocity += angularAcceleration * timeStep;
    angle += angularVelocity * timeStep;

    glutTimerFunc(10, Timer, 0);

    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'l': // creste lungimea
            pendulumLength += 0.1;
            break;
        case 'g': // creste acceleratia
            gravitationalAcceleration += 1.0;
            break;
        case 'L': // scade lungimea
            if (pendulumLength > 0.2) {
                pendulumLength -= 0.1;
            }
            break;
        case 'G': // scade acceleratia
            if (gravitationalAcceleration > 1.0) {
                gravitationalAcceleration -= 1.0;
            }
            break;
    }
}

void initGL() {
    glClearColor(0.5f, 0.1f, 0.2f, 0.5f);
}

// Function care deseneaza o linie si un punct
// care se misca asemenea unui pendul folosindu-se
// de calcule matematice pentru a mima actiunea de
// pendulare.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(0.3f, 0.5f, 1.0f);

    glBegin(GL_LINES);
    glVertex2f(-0.5f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    // PENDUL:
    glBegin(GL_LINES);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(pendulumLength * sin(angle), -pendulumLength * cos(angle));
    glEnd();


    glPointSize(15.0f);
    glBegin(GL_POINTS);
    glVertex2f(pendulumLength * sin(angle), -pendulumLength * cos(angle));
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Pendulum Simulation: Simpetru Eva-Maria 208 ID");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    initGL();

    glutTimerFunc(0, Timer, 0);

    glutMainLoop();
    return 0;
}
