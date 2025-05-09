#include <GL/glut.h>
#include <cmath>

float angle = 0.0;           // For rotating windmill blades
float carPosition = -1.0;    // For moving the car
float box1X = -1.0;          // First box
float box2X = 1.0;           // Second box

void drawWindmill() {
    // Draw windmill stand
    glColor3f(0.5, 0.3, 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, -0.5);
    glVertex2f(0.05, -0.5);
    glVertex2f(0.05, 0.2);
    glVertex2f(-0.05, 0.2);
    glEnd();

    // Draw blades
    glPushMatrix();
    glTranslatef(0.0, 0.2, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);

    glColor3f(0.8, 0.8, 0.8);
    for (int i = 0; i < 4; i++) {
        glBegin(GL_TRIANGLES);
        glVertex2f(0.0, 0.0);
        glVertex2f(-0.1, 0.4);
        glVertex2f(0.1, 0.4);
        glEnd();
        glRotatef(90.0, 0.0, 0.0, 1.0);
    }
    glPopMatrix();
}

void drawCar() {
    // Draw car body
    glColor3f(0.2, 0.5, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(-0.2, -0.1);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0.1);
    glVertex2f(-0.2, 0.1);
    glEnd();

    // Draw wheels
    glColor3f(0.1, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.1, -0.15, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.1, -0.15, 0.0);
    glutSolidSphere(0.05, 20, 20);
    glPopMatrix();
}

void drawBoxes() {
    // Box 1
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(box1X - 0.1, -0.3);
    glVertex2f(box1X + 0.1, -0.3);
    glVertex2f(box1X + 0.1, -0.1);
    glVertex2f(box1X - 0.1, -0.1);
    glEnd();

    // Box 2
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(box2X - 0.1, 0.1);
    glVertex2f(box2X + 0.1, 0.1);
    glVertex2f(box2X + 0.1, 0.3);
    glVertex2f(box2X - 0.1, 0.3);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw windmill
    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    drawWindmill();
    glPopMatrix();

    // Draw moving car
    glPushMatrix();
    glTranslatef(carPosition, -0.5, 0.0);
    drawCar();
    glPopMatrix();

    // Draw moving boxes
    drawBoxes();

    glutSwapBuffers();
}

void timer(int) {
    // Update windmill rotation
    angle += 2.0;
    if (angle >= 360.0)
        angle -= 360.0;

    // Update car position
    carPosition += 0.01;
    if (carPosition > 1.0)
        carPosition = -1.0;

    // Update boxes positions
    box1X += 0.01;
    box2X -= 0.01;
    if (box1X > 1.0)
        box1X = -1.0;
    if (box2X < -1.0)
        box2X = 1.0;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // Approximately 60 FPS
}

void init() {
    glClearColor(0.9, 0.9, 0.9, 1.0); // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Coordinate system
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Windmill and Moving Car Animation");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}
