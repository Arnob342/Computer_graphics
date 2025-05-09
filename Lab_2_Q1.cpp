#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

void All()
{


    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(239, 50, 10);
    glVertex2f(1, 1);
    glVertex2f(6, 1);
    glVertex2f(6, 2);
    glVertex2f(1, 2);
    glEnd();

    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(239, 229, 10); //

    glVertex2f(1, 2);
    glVertex2f(6, 2);
    glVertex2f(6, 3);
    glVertex2f(1, 3);
    glEnd();


    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(200, 144, 84); //
    glVertex2f(1, 3);
    glVertex2f(6, 3);
    glVertex2f(6, 4);
    glVertex2f(1, 4);
    glEnd();

    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(84, 173, 112); //
    glVertex2f(1, 4);
    glVertex2f(6, 4);
    glVertex2f(6, 5);
    glVertex2f(1, 5);
    glEnd();

    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(92, 176, 210); //
    glVertex2f(1, 5);
    glVertex2f(6, 5);
    glVertex2f(6, 6);
    glVertex2f(1, 6);
    glEnd();

    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(88, 123, 201); //
    glVertex2f(1, 6);
    glVertex2f(6, 6);
    glVertex2f(6, 7);
    glVertex2f(1, 7);
    glEnd();

    glBegin(GL_QUADS);  // quads Shape( axis ++ )
    glColor3ub(151, 91, 199); //
    glVertex2f(1, 7);
    glVertex2f(6, 7);
    glVertex2f(6, 8);

    glVertex2f(1, 8);
    glEnd();



}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    All();// function Call
    glEnd();
    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("RainBow");  // Create window with the given title
    glutInitWindowSize(320, 320);   // Set the window's initial width & height
    glutDisplayFunc(display);       // Register callback handler for window re-paint event                      // Our own OpenGL initialization
    gluOrtho2D(1, 6, 1, 8);
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}




