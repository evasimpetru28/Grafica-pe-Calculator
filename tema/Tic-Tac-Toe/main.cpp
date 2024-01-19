#include <GL/glut.h>
#include <iostream>
#include <array>
#include <cmath>

using namespace std;

array<array<char, 3>, 3> board = {{{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}};
bool xTurn = true; // false pentru jucatorul cu O

void drawX(float x, float y) {
    glBegin(GL_LINES);
    glVertex2f(x - 0.2f, y - 0.2f);
    glVertex2f(x + 0.2f, y + 0.2f);
    glVertex2f(x - 0.2f, y + 0.2f);
    glVertex2f(x + 0.2f, y - 0.2f);
    glEnd();
}

void drawO(float x, float y) {
    float radius = 0.2f;
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i += 10) {
        float degInRad = i * 3.14159f / 180.0f;
        glVertex2f(x + cos(degInRad) * radius, y + sin(degInRad) * radius);
    }
    glEnd();
}

void drawGrid() {
    glBegin(GL_LINES);
    glVertex2f(-0.33f, -1.0f);
    glVertex2f(-0.33f, 1.0f);
    glVertex2f(0.33f, -1.0f);
    glVertex2f(0.33f, 1.0f);
    glVertex2f(-1.0f, -0.33f);
    glVertex2f(1.0f, -0.33f);
    glVertex2f(-1.0f, 0.33f);
    glVertex2f(1.0f, 0.33f);
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int screenWidth = glutGet(GLUT_WINDOW_WIDTH);
        int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);
        float gridX = ((float) x / screenWidth) * 3.0f - 1.5f;
        float gridY = ((float) (screenHeight - y) / screenHeight) * 3.0f - 1.5f;
        int gridPosX = (gridX + 1.0f) * 3.0f / 2.0f;
        int gridPosY = (gridY + 1.0f) * 3.0f / 2.0f;

        // Pune 'X' sau 'O' daca era gol
        if (board[gridPosY][gridPosX] == ' ') {
            board[gridPosY][gridPosX] = xTurn ? 'X' : 'O';
            xTurn = !xTurn;
        }

        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawGrid();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float x = j * 0.66f - 1.0f + 0.33f;
            float y = i * 0.66f - 1.0f + 0.33f;
            if (board[i][j] == 'X') {
                drawX(x, y);
            } else if (board[i][j] == 'O') {
                drawO(x, y);
            }
        }
    }

    glFlush();
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Tic-Tac-Toe: Simpetru Eva-Maria 208 ID");

    initGL();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
