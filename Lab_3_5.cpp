#include <GL/glut.h>
#include <windows.h>
#include <math.h>

void drawRectangle(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float r, float g, float b, float a) {
    glColor4f(r, g, b, a);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glVertex2f(x4, y4);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void Moon(float x, float y) {
    glColor3ub(200, 200, 200); // Slightly dimmer moon color
    drawCircle(x, y, 4.0, 100);
}

void drawBuilding() {
    for (int i = 0; i < 5; i++) {
        drawRectangle(-12, 1 + i * 3 + 5, -2, 1 + i * 3 + 5, -2, 4 + i * 3 + 5, -12, 4 + i * 3 + 5, 0.2f, 0.2f, 0.3f, 1.0f); // Darker blue-gray
    }
}

void drawWindows() {
    // Brighter purple windows
    drawRectangle(-8, 5.5 + 5, -6, 5.5 + 5, -6, 6.5 + 5, -8, 6.5 + 5, 0.7f, 0.2f, 1.0f, 0.8f);
    drawRectangle(-8, 8.5 + 5, -6, 8.5 + 5, -6, 9.5 + 5, -8, 9.5 + 5, 0.7f, 0.2f, 1.0f, 0.8f);
    drawRectangle(-8, 11.5 + 5, -6, 11.5 + 5, -6, 12.5 + 5, -8, 12.5 + 5, 0.7f, 0.2f, 1.0f, 0.8f);
    drawRectangle(-8, 14.5 + 5, -6, 14.5 + 5, -6, 15.5 + 5, -8, 15.5 + 5, 0.7f, 0.2f, 1.0f, 0.8f);
}

void drawRoof() {
    drawRectangle(-12, 16 + 5, -2, 16 + 5, -2, 17 + 5, -12, 17 + 5, 0.3f, 0.3f, 0.3f, 0.8f); // Darker gray
}

void drawDoor() {
    drawRectangle(-9, 1 + 5, -5, 1 + 5, -5, 3 + 5, -9, 3 + 5, 0.2f, 0.1f, 0.0f, 1.0f); // Darker brown
}

void Tree() {
    glColor3f(0.2f, 0.1f, 0.0f); // Darker brown trunk
    glBegin(GL_QUADS);
    glVertex2f(6.80, 5.09);
    glVertex2f(9.20, 5.09);
    glVertex2f(9.19, 12);
    glVertex2f(6.79, 12);
    glEnd();

    // Dark green leaves
    glColor3ub(0, 50, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 20);
    glVertex2f(4, 16);
    glVertex2f(12, 16);
    glEnd();

    glColor3ub(0, 50, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 18);
    glVertex2f(4, 14);
    glVertex2f(12, 14);
    glEnd();

    glColor3ub(0, 50, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 16);
    glVertex2f(4, 12);
    glVertex2f(12, 12);
    glEnd();
}

void LAMP() {
    // Ground shadow for more realism
    glColor3ub(50, 50, 50);
    glBegin(GL_QUADS);
    glVertex2f(-15, -22);
    glVertex2f(-5, -22);
    glVertex2f(-7, -20);
    glVertex2f(-13, -20);
    glEnd();

    // Base of the lamppost (more detailed)
    glColor3ub(50, 25, 0); // Darker brown for base
    glBegin(GL_QUADS);
    glVertex2f(-13, -20);
    glVertex2f(-7.4, -20);
    glVertex2f(-7.4, -22);
    glVertex2f(-13, -22);
    glEnd();

    // Pole with gradient for metallic look
    glBegin(GL_QUADS);
    glColor3ub(60, 30, 0); // Darker at bottom
    glVertex2f(-11.30, -20.17);
    glVertex2f(-9.17, -20.17);
    glColor3ub(90, 45, 0); // Lighter at top
    glVertex2f(-9.17, -12);
    glVertex2f(-11.30, -12);
    glEnd();

    // Lamp housing (metal part)
    glColor3ub(40, 40, 40); // Darker metallic gray
    glBegin(GL_QUADS);
    glVertex2f(-14, -12);
    glVertex2f(-6, -12);
    glVertex2f(-7, -11);
    glVertex2f(-13, -11);
    glEnd();

    // Main light with gradient and glow effect
    // Outer light area (glow)
    glBegin(GL_TRIANGLES);
    glColor4ub(255, 245, 200, 50); // More subtle semi-transparent glow
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

    // Light rays effect (subtler)
    glBegin(GL_LINES);
    glColor4ub(255, 250, 220, 30); // More transparent rays
    for (int i = 0; i < 10; i++) {
        float angle = -0.5 + i * 0.1;
        glVertex2f(-9.99, -6.98);
        glVertex2f(-9.99 + 5 * sin(angle), -6.98 + 5 * cos(angle)); // Shorter rays
    }
    glEnd();
}

void BENCH() {
    // Darker brown wood
    glColor3ub(75, 37, 0);
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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0f, 0.05f, 0.1f, 1.0f); // Darker night sky
    Moon(-21.57, 21);
    drawBuilding();
    drawWindows();
    drawDoor();
    drawRoof();
    Tree();
    LAMP();
    BENCH();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(850, 860);
    glutCreateWindow("Moon, Building , Tree, Lamp, and Bench");
    gluOrtho2D(-30, 30, -30, 30);
    glClearColor(0.0f, 0.05f, 0.1f, 1.0f); // Darker night sky
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}