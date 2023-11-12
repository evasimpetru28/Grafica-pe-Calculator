#include <iostream>
#include <GL/glut.h>
#include<math.h>

using namespace std;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //glPointSize(40.0);
}

void display() {
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);//initializare desen poligon
    glVertex2f(0.0, 0.0); //stabilire coordonate triunghi
    glVertex2f(200.0, 200.0);
    glVertex2f(0.0, 200.0);
    glEnd();
    glFlush();
    glPointSize(40.0);
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int dist = 0, i = 1; i <= 3; i++) {
        glVertex2i(20 * i + dist, 20);//y
        dist += 20;

    }
    glEnd();
    glFlush();
}

void reshape(int w, int h)//functia redesenare
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);//stabilirea viewportului la dimensiunea ferestrei
    glMatrixMode(GL_PROJECTION);//specificare matrice modificabila la valoare argumentului de modificare
    glLoadIdentity();//initializarea sistemului de coordonate
    gluOrtho2D(0.0, (GLdouble) w, 0.0, (GLdouble) h);//stabileste volumul de vedere folosind o proiectie ortografica
}


int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("puncte");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}