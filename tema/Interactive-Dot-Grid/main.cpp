#include <GL/glut.h>
#include <vector>
#include <cmath>

const int gridWidth = 10;
const int gridHeight = 10;
const float dotRadius = 0.05f;
const float gridSpacing = 0.2f;

struct Dot {
    float x, y;
    float r, g, b;
    bool isOn;
};

std::vector<Dot> dots;

void initDots() {
    for (int i = 0; i < gridHeight; ++i) {
        for (int j = 0; j < gridWidth; ++j) {
            Dot dot = {
                    j * gridSpacing - ((gridWidth - 1) * gridSpacing) / 2.0f,
                    i * gridSpacing - ((gridHeight - 1) * gridSpacing) / 2.0f,
                    false
            };
            dots.push_back(dot);
        }
    }
}

void drawDot(float x, float y, bool isOn, float r, float g, float b) {
    glColor3f(isOn ? r : 0.5f, isOn ? g : 0.5f, isOn ? b : 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    for (int angle = 0; angle < 360; angle += 5) {
        float rad = angle * 3.14159265358979323846f / 180.0f;
        glVertex2f(x + cos(rad) * dotRadius, y + sin(rad) * dotRadius);
    }
    glEnd();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        float gridX = ((float) x / windowWidth) * gridWidth * gridSpacing - ((gridWidth * gridSpacing) / 2.0f);
        float gridY = (((float) (windowHeight - y) / windowHeight) * gridHeight * gridSpacing) -
                      ((gridHeight * gridSpacing) / 2.0f);

        for (auto &dot: dots) {
            if (sqrt(pow(dot.x - gridX, 2) + pow(dot.y - gridY, 2)) < dotRadius) {
                dot.isOn = !dot.isOn;

                // culoare random
                dot.r = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                dot.g = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                dot.b = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
                break;
            }
        }
        glutPostRedisplay();
    }
}

// Functie care deseneaza un grid de puncte
// Fiecare punct isi schimba culoarea random la primul click
// si se coloreaza gri la al doilea click
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (const auto &dot: dots) {
        drawDot(dot.x, dot.y, dot.isOn, dot.r, dot.g, dot.b);
    }
    glFlush();

}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutCreateWindow("Interactive Dot Grid: Simpetru Eva-Maria 208 ID");

    initGL();
    initDots();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}
