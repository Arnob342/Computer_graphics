#include <GL/glut.h>

float box1X = 0.0f;   // Will move right
float box2X = 10.0f;  // Will move left
float speed = 0.05f;

void drawBox(float x, float y) {
    glBegin(GL_QUADS);
        glVertex2f(x + 2, y + 2);
        glVertex2f(x + 4, y + 2);
        glVertex2f(x + 4, y + 4);
        glVertex2f(x + 2, y + 4);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Red box moving right
    glColor3f(1, 0, 0);
    drawBox(box1X, 5);

    // Blue box moving left
    glColor3f(0, 0, 1);
    drawBox(box2X, 2);

    glutSwapBuffers();
}

void update(int value) {
    box1X += speed;
    box2X -= speed;

    // Loop boxes back
    if (box1X > 20) box1X = -4;
    if (box2X < -4) box2X = 20;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);           
    gluOrtho2D(-2, 16, -2, 10); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Moving Boxes");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();
    return 0;
}
