#include <windows.h>
#include <GL/glut.h>
#include <iostream>

// Display flag to toggle between objects
int currentDisplay = 1;

// Display for Object 1
void displayObject1() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the axis (orthographic projection) for Object 1
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50, 50, -50, 50);

    // Draw Object 1 (Red Triangle)
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_TRIANGLES);
        glVertex2i(-20, -20);
        glVertex2i(20, -20);
        glVertex2i(0, 30);
    glEnd();

    glFlush();
}

// Display for Object 2
void displayObject2() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the axis (orthographic projection) for Object 2
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);

    // Draw Object 2 (Blue Square)
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_QUADS);
        glVertex2i(30, 30);
        glVertex2i(70, 30);
        glVertex2i(70, 70);
        glVertex2i(30, 70);
    glEnd();

    glFlush();
}

// Keyboard input function to switch between displays
void keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentDisplay = 1; // Switch to Object 1
        glutPostRedisplay();
    } else if (key == '2') {
        currentDisplay = 2; // Switch to Object 2
        glutPostRedisplay();
    }
}

// Main display function
void display() {
    if (currentDisplay == 1) {
        displayObject1();
    } else if (currentDisplay == 2) {
        displayObject2();
    }
}

// Initialization
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Keyboard-Controlled Displays");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
