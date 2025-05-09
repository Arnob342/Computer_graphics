#include <GL/glut.h>

void BENCH() {
    // Bench legs (front)
    glColor3ub(150, 75, 0); // Brown wood color
    glBegin(GL_QUADS);
    // Left front leg
    glVertex2f(2, -20);
    glVertex2f(3, -20);
    glVertex2f(3, -16);
    glVertex2f(2, -16);


    // Right front leg
    glVertex2f(8, -20);
    glVertex2f(9, -20);
    glVertex2f(9, -16);
    glVertex2f(8, -16);
    glEnd();

    // Bench legs (back)
    glBegin(GL_QUADS);
    // Left back leg
    glVertex2f(2, -18);
    glVertex2f(3, -18);
    glVertex2f(3, -14);
    glVertex2f(2, -14);

    // Right back leg
    glVertex2f(8, -18);
    glVertex2f(9, -18);
    glVertex2f(9, -14);
    glVertex2f(8, -14);
    glEnd();

    // Bench seat
    glBegin(GL_QUADS);
    glVertex2f(1.5, -16);
    glVertex2f(9.5, -16);
    glVertex2f(9.5, -15);
    glVertex2f(1.5, -15);
    glEnd();

    // Bench back
    glBegin(GL_QUADS);
    glVertex2f(1.5, -15);
    glVertex2f(9.5, -15);
    glVertex2f(10.5, -12);
    glVertex2f(2.5, -12);
    glEnd();

}

void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    BENCH(); // Draw only the bench
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Park Bench");
    gluOrtho2D(-3, 13, -22, -6); // Adjusted coordinate system
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}
