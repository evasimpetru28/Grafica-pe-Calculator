#include <GL/glut.h>
#include <ctime>
#include <cmath>

float secondsAngle;
float minutesAngle;
float hoursAngle;

void drawHand(float length, float angle, float lineWidth) {
    glLineWidth(lineWidth),
            glBegin(GL_LINES);
    glVertex2f(0, 0);
    glVertex2f(length * cos(angle), length * sin(angle));
    glEnd();
}

void drawClockFace() {
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++) {
        float angle = 2.0f * 3.14159f * i / 360.0f;
        glVertex2f(cos(angle), sin(angle));
    }
    glEnd();
}

// Functie care afiseaza limbile unui ceas
// in functie de ora cutenta reala
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);
    drawClockFace();

    // Hours hand
    glColor3f(1, 0.2, 0.6);
    drawHand(0.5, hoursAngle + 3.14159f / 2.0f, 10);

    // Minutes hand
    glColor3f(0.7, 0.7, 0.1);
    drawHand(0.7, minutesAngle + 3.14159f / 2.0f, 5);

    // Seconds hand
    glColor3f(0.5, 0.3, 0.8);
    drawHand(0.9, secondsAngle + 3.14159f / 2.0f, 2);

    glFlush();
}

void Timer(int value) {

    time_t rawtime = time(nullptr);
    struct tm *currentTime = localtime(&rawtime);

    secondsAngle = -2.0f * 3.14159f * (currentTime->tm_sec / 60.0f);
    minutesAngle = -2.0f * 3.14159f * (currentTime->tm_min / 60.0f);
    hoursAngle = -2.0f * 3.14159f * ((currentTime->tm_hour % 12) / 12.0f);

    glutTimerFunc(10, Timer, 0);
    glutPostRedisplay();
}

void initGL() {
    glClearColor(0.3f, 0.7f, 0.5f, 0.2f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutCreateWindow("2D Clock: Simpetru Eva-Maria 208 ID");

    glutDisplayFunc(display);
    initGL();

    glutTimerFunc(0, Timer, 0);

    glutMainLoop();
    return 0;
}