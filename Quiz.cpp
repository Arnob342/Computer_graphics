#include <GL/glut.h>
#include <cmath>
#include <vector>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 0.0f); // Black lines
    glLineWidth(2.0f);

    // Draw the top 80% of the circle
    float circleRadius = 0.6f;
    float circleCenterY = 0.3f;
    int numSegments = 100;
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= static_cast<int>(0.8 * numSegments); ++i) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = circleRadius * cos(angle);
        float y = circleRadius * sin(angle) + circleCenterY;
        glVertex2f(x, y);
    }
    glEnd();

    // Draw lines from the middle of the circle to the bottom, forming hills
    int numHills = 5;
    for (int i = 0; i < numHills; ++i) {
        float fraction = static_cast<float>(i + 1) / (numHills + 1);
        float middleX = fraction * 0.8f - 0.4f; // Spread the x-coordinates
        float middleY = circleCenterY;
        float bottomX = middleX;
        float bottomY = -0.8f - fraction * 0.1f; // Vary the bottom slightly for hill shape

        glBegin(GL_LINES);
        glVertex2f(middleX, middleY);
        glVertex2f(bottomX, bottomY);
        glEnd();

        // Add small hill bumps
        float bumpOffset = 0.1f;
        glBegin(GL_LINE_STRIP);
        for (int j = -5; j <= 5; ++j) {
            float hillX = bottomX + j * 0.02f;
            float hillY = bottomY + bumpOffset * exp(-(j * j) / 4.0f);
            glVertex2f(hillX, hillY);
        }
        glEnd();
    }

    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle with Hills");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // White background
    glutMainLoop();
    return 0;
}