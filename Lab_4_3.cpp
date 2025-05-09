#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include <cmath>      // For math functions

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glColor3ub(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float angle = (i * 2 * pi) / 200;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawEllipse(float cx, float cy, float rx, float ry, int num_segments) {
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = rx * cosf(theta); // X radius
        float y = ry * sinf(theta); // Y radius
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void lighthouse()
{
    glColor3ub(0, 0, 0);

    // Lower window
    glBegin(GL_LINE_LOOP);
        glVertex2f(27, 24);
        glVertex2f(30, 24);
        glVertex2f(30, 20);
        glVertex2f(27, 20);
    glEnd();

    // Upper window
    glBegin(GL_LINE_LOOP);
        glVertex2f(27, 34);
        glVertex2f(30, 34);
        glVertex2f(30, 38);
        glVertex2f(27, 38);
    glEnd();

    // Base structure
    glBegin(GL_LINE_LOOP);
        glVertex2f(24, 42);
        glVertex2f(33, 42);
        glVertex2f(34, 15);
        glVertex2f(23, 15);
    glEnd();

    // Layers
    glBegin(GL_LINE_LOOP);
        glVertex2f(24, 42);
        glVertex2f(33, 42);
        glVertex2f(33.5, 44);
        glVertex2f(23.5, 44);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(23.5, 44);
        glVertex2f(22, 46);
        glVertex2f(35, 46);
        glVertex2f(33.5, 44);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(22, 46);
        glVertex2f(22, 48);
        glVertex2f(35, 48);
        glVertex2f(35, 46);
    glEnd();

    // Top windows and triangle roof
    glBegin(GL_LINE_LOOP);
        glVertex2f(26, 52);
        glVertex2f(30, 52);
        glVertex2f(30, 48);
        glVertex2f(26, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(32, 48);
        glVertex2f(32, 55);
        glVertex2f(24, 55);
        glVertex2f(24, 48);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(27.5, 58);
        glVertex2f(23, 55);
        glVertex2f(32, 55);
    glEnd();

    // Ground line
    glBegin(GL_LINES);
        glVertex2f(0, 15);
        glVertex2f(60, 15);
    glEnd();

    // Light rays (optional)
    glBegin(GL_LINES);
        // Right
        glVertex2f(36, 48); glVertex2f(55, 55);
        glVertex2f(36, 46); glVertex2f(55, 46);
        glVertex2f(36, 44); glVertex2f(55, 37);

        // Left
        glVertex2f(20, 48); glVertex2f(5, 55);
        glVertex2f(20, 46); glVertex2f(5, 46);
        glVertex2f(20, 44); glVertex2f(5, 37);
    glEnd();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);        // Clear the screen

    glLineWidth(2.0f); // Set line width

    lighthouse();

    // Draw ellipse base
    drawEllipse(30, 15, 18, 5, 100);

    // Filled polygon to represent shadow under base
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
        glVertex2d(12, 16);
        glVertex2d(48, 16);
        glVertex2d(48, 0);
        glVertex2d(12, 0);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(750, 600);
    glutCreateWindow("Lighthouse Scene");

    // Coordinate system set to X: 0–60, Y: 0–80
    gluOrtho2D(0, 60, 0, 80);

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
