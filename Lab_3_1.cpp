#include <GL/glut.h>

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void drawBuilding() {
    for (int i = 0; i < 5; i++) {
        drawRectangle(-12, -4 + i * 3, -2, -4 + i * 3, -2, -1 + i * 3, -12, -1 + i * 3, 0.83, 0.83, 0.83, 1.0);
    }
}

void drawWindows() {
    // Purple windows 
    drawRectangle(-8, 0.5, -6, 0.5, -6, 1.5, -8, 1.5, 0.5, 0.0, 0.8, 0.6);
    drawRectangle(-8, 3.5, -6, 3.5, -6, 4.5, -8, 4.5, 0.5, 0.0, 0.8, 0.6);
    drawRectangle(-8, 6.5, -6, 6.5, -6, 7.5, -8, 7.5, 0.5, 0.0, 0.8, 0.6);
    drawRectangle(-8, 9.5, -6, 9.5, -6, 10.5, -8, 10.5, 0.5, 0.0, 0.8, 0.6);
}

void drawRoof() {
    drawRectangle(-12, 11, -2, 11, -2, 12, -12, 12, 0.5, 0.5, 0.5, 0.8);
}

void drawDoor() {
    drawRectangle(-9, -4, -5, -4, -5, -2, -9, -2, 0.5, 0.3, 0.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);  // Black background

    drawBuilding();
    drawWindows();
    drawDoor();
    drawRoof();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Building with Door");

    // Use a simple 2D orthogonal projection that fits within (-15, 15) for x and (-5, 15) for y
    gluOrtho2D(-20, 5, -5, 15);  // x from -15 to 15, y from -5 to 15

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
