#include <GL/glut.h>

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

void initGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glPointSize(50.0);
    glShadeModel(GL_FLAT);

}

void drawCube() {
    glBegin(GL_QUADS);

    // Top (y = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);

    // Bottom (y = -1.0f)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // Front  (z = 0.5f)
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // Back (z = -0.5f)
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    // Left (x = -0.5f)
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);

    // Right (x = 0.5f)
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    glEnd();
    glFlush();
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) {
        height = 1;
    }
    GLfloat aspect = (GLfloat) width / (GLfloat) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y) {
    const float angleStep = 5.0f;
    switch (key) {
        case 'x':
            angleX += angleStep;
            break;
        case 'y':
            angleY += angleStep;
            break;
        case 'z':
            angleZ += angleStep;
            break;
        case 'a':
            angleX -= angleStep;
            break;
        case 'b':
            angleY -= angleStep;
            break;
        case 'c':
            angleZ -= angleStep;
            break;
    }
    glutPostRedisplay();
}

// Functie care deseneaza un cub si il roteste
// pe axele X, Y, Z, respectiv, in functie de un unghi
// in momentul apasarii tastelor x, y, z, respectiv,
// pentru un sens, si a, b, c, respectiv, pentru sensul opus.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); // x axis
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); // y axis
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f); // z axis

    drawCube();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);\
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(400, 400);
    glutCreateWindow("Rotating 3D Cube: Simpetru Eva-Maria 208 ID");

    initGL();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
