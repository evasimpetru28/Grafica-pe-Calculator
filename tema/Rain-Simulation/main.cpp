#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Raindrop {
    float x, y;
    float speed;
    float length;   // lungimea picaturii
};

const int dropsNumber = 250;
vector<Raindrop> raindrops;

void initRaindrops() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    for (int i = 0; i < dropsNumber; i++) {
        Raindrop drop;
        drop.x = (rand() % 2000 - 1000) / 1000.0f;
        drop.y = (rand() % 2000 - 1000) / 1000.0f;
        drop.speed = 0.001f + (rand() % 100) / 100000.0f;
        drop.length = 0.01f + (rand() % 10) / 1000.0f;
        raindrops.push_back(drop);
    }
}

void initGL() {
    glClearColor(0.3f, 0.2f, 0.7f, .4f);
}

void Timer(int value) {
    for (auto &drop: raindrops) {
        drop.y -= drop.speed; // simuleaza actiunea de cadere a picaturii
        if (drop.y < -1) {
            drop.y = 1;
            drop.x = (rand() % 2000 - 1000) / 1000.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, Timer, 0);
}

// Functie care deseneaza 250 (dropsNumber) picaturi de ploaie
// care au ca lungimea, pozitie si viteza cate un numar random,
// Caderea picaturilor este simulata prin decrementarea lui y
// Daca picatura iese din ecran (y < -1), se genereaza una noua
// si are y = 1 pentru a aparea in partea de sus a ecranului
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glColor3f(0.5f, 0.5f, 1.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
    for (const auto &drop: raindrops) {
        glVertex2f(drop.x, drop.y);
        glVertex2f(drop.x, drop.y + drop.length);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(400, 400);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Rain Simulation: Simpetru Eva-Maria 208 ID");
    initGL();
    initRaindrops();
    glutDisplayFunc(display);

    glutTimerFunc(0, Timer, 0);

    glutMainLoop();
    return 0;
}