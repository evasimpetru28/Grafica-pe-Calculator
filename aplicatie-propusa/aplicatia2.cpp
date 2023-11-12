#include <GL/freeglut.h>

int block_nr = 17;

int psize = 40;
int distx = 0;
int disty = 0;

///////////////////////////////////////////////////////
// MAKE WINDOW SIZE DEPENDING ON BLOCKS NUMBER
int WINDOW_WIDTH = block_nr * 40 + 100;
int WINDOW_HEIGHT = (block_nr / 2 + 1) * 40 + 100;
///////////////////////////////////////////////////////

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(psize);
    glBegin(GL_POINTS);
    disty = 20;

    if (block_nr % 2 == 0) {
        block_nr--; // If even, decrease to make it an odd number of blocks
    }

    int current_blocks_number = block_nr;
    int level = 1;
    while (current_blocks_number >= 1) {
        distx += 40;
        for (int j = 0; j < current_blocks_number; j++) {
            double r = ((double) rand() / (RAND_MAX));
            double g = ((double) rand() / (RAND_MAX));
            double b = ((double) rand() / (RAND_MAX));
            glColor3d(r, g, b);
            glVertex2i(40 * j + distx, 40 * level + disty);
        }
        level++;
        current_blocks_number -= 2;
    }
    glEnd();
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Puncte cu for");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}