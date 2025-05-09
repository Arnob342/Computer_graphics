#include <windows.h>
#include <GL/glut.h>
#include <math.h>

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

// **Flag of Bangladesh
void drawBangladeshFlag(float x, float y) {
    glBegin(GL_QUADS);
    glColor3ub(0, 106, 78); // Green
    glVertex2f(x + 1, y + 1);
    glVertex2f(x + 4, y + 1);
    glVertex2f(x + 4, y + 3);
    glVertex2f(x + 1, y + 3);
    glEnd();

    glColor3ub(244, 42, 65); // Red
    drawCircle(x + 2.52, y + 1.99, 0.6, 100); // Circle in the center
}

// **Flag of Japan 
void drawJapanFlag(float x, float y) {
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White
    glVertex2f(x + 5, y + 1);
    glVertex2f(x + 8, y + 1);
    glVertex2f(x + 8, y + 3);
    glVertex2f(x + 5, y + 3);
    glEnd();

    glColor3ub(188, 0, 45); // Red
    drawCircle(x + 6.57, y + 2.02, 0.6, 100); // Circle in the center
}



// **Flag of Italy
void drawSierraLeoneFlag(float x, float y) {
    glBegin(GL_QUADS);
    glColor3ub(0, 158, 73); // Green
    glVertex2f(x - 11, y + 4);
    glVertex2f(x - 12, y + 4);
    glVertex2f(x - 12, y + 6.02);
    glVertex2f(x - 11, y + 6.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White
    glVertex2f(x - 11, y + 4);
    glVertex2f(x - 10, y + 4);
    glVertex2f(x - 10, y + 6.02);
    glVertex2f(x - 11, y + 6.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(206, 17, 38); // Red
    glVertex2f(x - 10, y + 4);
    glVertex2f(x - 9, y + 4);
    glVertex2f(x - 9, y + 6.02);
    glVertex2f(x - 10, y + 6.02);
    glEnd();

}

// **Flag of France
void drawLuxembourgFlag(float x, float y) {
    glBegin(GL_QUADS);
    glColor3ub(0, 161, 222); // Blue
    glVertex2f(x - 13, y + 4);
    glVertex2f(x - 12, y + 4);
    glVertex2f(x - 12, y + 6.02);
    glVertex2f(x - 13, y + 6.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White
    glVertex2f(x - 12, y + 4);
    glVertex2f(x - 11, y + 4);
    glVertex2f(x - 11, y + 6.02);
    glVertex2f(x - 12, y + 6.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(206, 17, 38); // Red
    glVertex2f(x - 11, y + 4);
    glVertex2f(x - 10, y + 4);
    glVertex2f(x - 10, y + 6.02);
    glVertex2f(x - 11, y + 6.02);
    glEnd();

}
//flage of Ireland
void drawLithuaniaFlag(float x, float y) {

    glBegin(GL_QUADS);
    glColor3ub(0, 106, 68); // Green
    glVertex2f(x + 0.80, y + 4);
    glVertex2f(x + 1.78, y + 3.99);
    glVertex2f(x + 1.78, y + 6);
    glVertex2f(x + 0.80, y + 6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255); // White
    glVertex2f(x + 1.78, y + 3.99);
    glVertex2f(x + 2.80, y + 3.99);
    glVertex2f(x + 2.78, y + 6);
    glVertex2f(x + 1.78, y + 6);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 165, 0); // Orange
    glVertex2f(x + 2.78, y + 3.99);
    glVertex2f(x + 3.70, y + 3.99);
    glVertex2f(x + 3.70, y + 6);
    glVertex2f(x + 2.78, y + 6);
    glEnd();

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw flags with specified spacing
    drawBangladeshFlag(1, 1);    // Position: (1, 1)
    drawJapanFlag(4, 1);         // Position: (4, 1) (1 + 1 + 2 = 4)
    drawLithuaniaFlag(9, 1);     // Position: (9, 1) (4 + 3 + 2 = 9)
    drawSierraLeoneFlag(14, 1);  // Position: (14, 1) (9 + 5 + 0 = 14)
    drawLuxembourgFlag(19, 1);   // Position: (19, 1) (14 + 5 + 0 = 19)

    glFlush();
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 15, 0, 8); // Adjusted to fit the new positions
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500); // Adjusted window size
    glutCreateWindow("Flags of Bangladesh, Japan, Italy, France, and Ireland");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}