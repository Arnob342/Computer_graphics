#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
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
    // Circle layers at the base
   // circle(19.5, 0, 20, 1, 1, 1);       // Inner dark circle
   // circle(17.5, 0, 20, 255, 255, 255); // Outer white circle

    glColor3ub(1, 1, 1);
    glBegin(GL_LINE_LOOP); // Below window
        glVertex2f(-2, 56);
        glVertex2f(1, 56);
        glVertex2f(1, 50);
        glVertex2f(-2, 50);
    glEnd();

    glBegin(GL_LINE_LOOP); // Upper window
        glVertex2f(-2, 75);
        glVertex2f(1, 75);
        glVertex2f(1, 80);
        glVertex2f(-2, 80);
    glEnd();

    glBegin(GL_LINE_LOOP); // Full square (base structure)
        glVertex2f(-5, 85);
        glVertex2f(4, 85);
        glVertex2f(6, 37);
        glVertex2f(-7, 37);
    glEnd();

    // Layers above the lighthouse
    glBegin(GL_LINE_LOOP); // 1st layer
        glVertex2f(-5, 85);
        glVertex2f(4, 85);
        glVertex2f(5, 88);
        glVertex2f(-6, 88);
    glEnd();

    glBegin(GL_LINE_LOOP); // 2nd layer
        glVertex2f(-6, 88);
        glVertex2f(-8, 92);
        glVertex2f(7, 92);
        glVertex2f(5, 88);
    glEnd();

    glBegin(GL_LINE_LOOP); // 3rd layer
        glVertex2f(-8, 92);
        glVertex2f(-8, 96);
        glVertex2f(7, 96);
        glVertex2f(7, 92);
    glEnd();

    // Top windows and triangle roof
    glBegin(GL_LINE_LOOP); // Small square
        glVertex2f(-3, 105);
        glVertex2f(2, 105);
        glVertex2f(2, 96);
        glVertex2f(-3, 96);
    glEnd();

    glBegin(GL_LINE_LOOP); // Big square
        glVertex2f(4, 96);
        glVertex2f(4, 110);
        glVertex2f(-5, 110);
        glVertex2f(-5, 96);
    glEnd();

    glBegin(GL_LINE_LOOP); // Roof triangle
        glVertex2f(-0.5, 117);
        glVertex2f(-7, 110);
        glVertex2f(6, 110);
    glEnd();

    // Ground line
    glBegin(GL_LINES);
        glVertex2f(-120, 20);
        glVertex2f(120, 20);
    glEnd();

    // Right lines
    glBegin(GL_LINES);
        glVertex2f(12, 97); glVertex2f(40, 112);
        glVertex2f(12, 94); glVertex2f(46, 94);
        glVertex2f(12, 91.5); glVertex2f(40, 70);

        // Left lines
        glVertex2f(-12, 97); glVertex2f(-40, 112);
        glVertex2f(-12, 94); glVertex2f(-40, 94);
        glVertex2f(-12, 91.5); glVertex2f(-40, 70);
    glEnd();
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);        // Clear the screen

    glLineWidth(2.0f); // Set line width for structure
    lighthouse();
    drawEllipse(0, 20, 35, 17, 100); // Draw the base circle
    glBegin(GL_POLYGON); // Draw the top circle
    glColor3ub(255, 255, 255);
    glVertex2d(-35, 21);
    glVertex2d(35, 21);
    glVertex2d(35, -20);
    glVertex2d(-35, -20);
    glEnd();

    glFlush(); // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitWindowSize(750, 600);                  // Set the window's initial width & height
    glutCreateWindow("Lighthouse Scene");          // Create a window with the given title
    gluOrtho2D(-100, 100, 0, 130);                 // Set orthographic projection
    glutDisplayFunc(display);                      // Register display callback handler
    glutIdleFunc(display);                         // Refresh continuously
    glutMainLoop();                                // Enter the event-processing loop
    return 0;
}
