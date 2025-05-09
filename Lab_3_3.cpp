#include <GL/glut.h>
#include <math.h>

void LAMP() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Ground shadow for more realism
    glColor3ub(100, 100, 100);
    glBegin(GL_QUADS);
    glVertex2f(-15, -22);
    glVertex2f(-5, -22);
    glVertex2f(-7, -20);
    glVertex2f(-13, -20);
    glEnd();

    // Base of the lamppost (more detailed)
    glColor3ub(100, 50, 0); // Darker brown for base
    glBegin(GL_QUADS);
    glVertex2f(-13, -20);
    glVertex2f(-7.4, -20);
    glVertex2f(-7.4, -22);
    glVertex2f(-13, -22);
    glEnd();

    // Pole with gradient for metallic look
    glBegin(GL_QUADS);
    glColor3ub(120, 60, 0); // Darker at bottom
    glVertex2f(-11.30, -20.17);
    glVertex2f(-9.17, -20.17);
    glColor3ub(180, 90, 0); // Lighter at top
    glVertex2f(-9.17, -12);
    glVertex2f(-11.30, -12);
    glEnd();

    // Lamp housing (metal part)
    glColor3ub(80, 80, 80); // Metallic gray
    glBegin(GL_QUADS);
    glVertex2f(-14, -12);
    glVertex2f(-6, -12);
    glVertex2f(-7, -11);
    glVertex2f(-13, -11);
    glEnd();

    // Main light with gradient and glow effect
    // Outer light area (glow)
    glBegin(GL_TRIANGLES);
    glColor4ub(255, 245, 200, 100); // Semi-transparent
    glVertex2f(-9.99, -5.98);
    glColor4ub(255, 245, 200, 0); // Fading out
    glVertex2f(-16, -12);
    glColor4ub(255, 245, 200, 0);
    glVertex2f(-4, -12);
    glEnd();

    // Inner light (more intense)
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 250, 220); // Bright white
    glVertex2f(-9.99, -6.98);
    glColor3ub(255, 240, 200); // Warm white
    glVertex2f(-14, -12);
    glColor3ub(255, 240, 200);
    glVertex2f(-6, -12);
    glEnd();

    // Light rays effect
    glBegin(GL_LINES);
    glColor4ub(255, 250, 220, 100);
    for (int i = 0; i < 10; i++) {
        float angle = -0.5 + i * 0.1;
        glVertex2f(-9.99, -6.98);
        glVertex2f(-9.99 + 10 * sin(angle), -6.98 + 10 * cos(angle));
    }
    glEnd();

    glutSwapBuffers();
}

void Display()
{
    glClearColor(0,0,0,0); // Black background for contrast
    glClear(GL_COLOR_BUFFER_BIT);
    LAMP();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("Realistic Lamppost");
    gluOrtho2D(-22, 2, -30, 10);
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}