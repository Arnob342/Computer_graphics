#include <GL/glut.h>

void Tree() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glColor3f(0.5, 0.3, 0.0);// Brown trunk color
    glBegin(GL_QUADS);
        glVertex2f(6.80, 5.09);
        glVertex2f(9.20, 5.09);
        glVertex2f(9.19, 12);
        glVertex2f(6.79, 12);
    glEnd();
    
    // Green leaves (3 triangle layers)
    glColor3ub(0, 128, 0 );//Green color
    glBegin(GL_TRIANGLES);
        glVertex2f(8, 20);
        glVertex2f(4, 16);
        glVertex2f(12, 16);
    glEnd();
    
    glColor3ub(0, 128, 0 );//Green color
    glBegin(GL_TRIANGLES);
        glVertex2f(8, 18);
        glVertex2f(4, 14);
        glVertex2f(12, 14);
    glEnd();
    
    glColor3ub(0, 128, 0);//Green color
    glBegin(GL_TRIANGLES);
    glVertex2f(8, 16);
        glVertex2f(4, 12);
        glVertex2f(12, 12);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Simple Tree");
    gluOrtho2D(-6, 24, 0, 24);
    glutDisplayFunc(Tree);
    glutMainLoop();
    return 0;
}