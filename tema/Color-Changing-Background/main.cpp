#include <GL/glut.h>

float r = 0.0, g = 0.0, b = 0.0;
float val = 0.1;

void update(int value) {

    if (r >= 0.0 && r < 1.0) {
        r += val;
    } else if (g >= 0.0 && g < 1.0) {
        g += val;
    } else if (b >= 0.0 && b < 1.0) {
        b += val;
    } else {
        r = 0.0;
        g = 0.0;
        b = 0.0;
    }
    glClearColor(r, g, b, 1.0f);

    glutTimerFunc(50, update, 0);
    glutPostRedisplay();
}

// Functie care schimba culoarea background-ului
// folosind un set de culori calculate
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glFlush();
}

void initGL() {
    glClearColor(0.1, 0.1, 0.1, 1.0);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Color-Changing Background: Simpetru Eva-Maria 208 ID");

    initGL();
    glutDisplayFunc(display);

    glutTimerFunc(0, update, 0);

    glutMainLoop();

    return 0;
}
