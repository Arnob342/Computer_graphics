#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set background color to white
    glClearColor(1.0, 1.0, 1.0, 1.0);

    // Draw the trunk of the tree (brown rectangle)
    glColor3f(0.55, 0.27, 0.07); // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f, -0.5f);
    glVertex2f(0.1f, -0.5f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glEnd();

    // Draw the leaves of the tree (green triangle)
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3f, 0.0f);
    glVertex2f(0.3f, 0.0f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple Tree");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
