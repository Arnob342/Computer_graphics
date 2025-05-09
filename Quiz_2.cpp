#include <GL/glut.h>
#include <cmath>


// Function to draw the hill
void drawHill() {
    glColor3f(0.0f, 0.0f, 0.0f); // Set line color to black

    glBegin(GL_LINE_STRIP);
    for (float x = -5.0f; x <= 5.0f; x += 0.2f) {
        float y = 2.0f * exp(-(x * x) / 2.0f); // Gaussian-like curve for the hill
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINES);
    for (float x = -5.0f; x <= 5.0f; x += 1.0f) {
        float y = 2.0f * exp(-(x * x) / 2.0f);
        glVertex2f(x, y);
        glVertex2f(x, 0.0f); // Draw lines down to the base
    }
    glEnd();
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background to white
    glClear(GL_COLOR_BUFFER_BIT);

    // Set up the coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6.0, 6.0, 0.0, 3.0); // Adjust ranges as needed

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawHill();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Lined Hill");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}