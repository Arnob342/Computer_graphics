#include <windows.h>  // for MS Windows

#include <GL/glut.h>  // GLUT, include glu.h and gl.h

#include <math.h>

#include <cmath>

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_STRIP);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}


void hill()
{
    circle(75, 4, 89, 1, 1, 1);
    circle(71, 4, 89, 255, 255, 255);

    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(12, 16); //C
    glVertex2f(80, 16); //D

    glVertex2f(20, 16); //M
    glVertex2f(28, 21); //N

    glVertex2f(28, 21); //N
    glVertex2f(37, 29); //O

    glVertex2f(37, 29); //O
    glVertex2f(44, 29.5); //P

    glVertex2f(44, 29.5); //P
    glVertex2f(49, 33); //E

    glVertex2f(49, 33); //E
    glVertex2f(58, 26); //Q

    glVertex2f(58, 26); //E
    glVertex2f(60, 24); //Q


    glVertex2f(60, 24); //Q
    glVertex2f(72, 16); //I

    glEnd();
    //hill end


    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(42, 29); //F
    glVertex2f(44, 26); //E

    glVertex2f(44, 26); //E
    glVertex2f(42, 23); //L

    glVertex2f(45, 19); //M
    glVertex2f(40, 17); //N

    glEnd();


    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(28, 18); //C
    glVertex2f(38, 18); //O

    glVertex2f(31, 21); //O
    glVertex2f(39, 21); //P

    glVertex2f(34, 24); //P
    glVertex2f(41, 24); //Q

    glVertex2f(37, 26); //Q
    glVertex2f(42, 26); //R


    glEnd();
    //end hilles 2

    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(17, 16); //Q
    glVertex2f(17, 27); //R

    glVertex2f(13, 19); //Q
    glVertex2f(17, 21); //R

    glVertex2f(17, 21); //R
    glVertex2f(21, 19); //R

    glVertex2f(13, 22); //R
    glVertex2f(17, 24); //R

    glVertex2f(17, 24); //R
    glVertex2f(21, 22); //R

    glVertex2f(12.5, 24.5); //R
    glVertex2f(17, 27); //R

    glVertex2f(17, 27); //R
    glVertex2f(21, 24.5); //R

    glEnd();

    //tree end 

    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(76, 16); //Q
    glVertex2f(76, 27); //R

    glVertex2f(72, 19); //Q
    glVertex2f(76, 21); //R

    glVertex2f(76, 21); //R
    glVertex2f(80, 19); //R

    glVertex2f(72, 22); //R
    glVertex2f(76, 24); //R

    glVertex2f(76, 24); //R
    glVertex2f(80, 22); //R

    glVertex2f(71.5, 24.5); //R
    glVertex2f(76, 27); //R

    glVertex2f(76, 27); //R
    glVertex2f(80, 24.5); //R



    glEnd();


    glBegin(GL_LINES);
    glColor3ub(1, 1, 1);

    glVertex2f(27, 38); //R
    glVertex2f(42, 38); //R

    glVertex2f(25, 30); //R
    glVertex2f(33, 30); //R

    glVertex2f(50, 35); //R
    glVertex2f(64, 35); //R

    glVertex2f(59, 28); //R
    glVertex2f(67, 28); //R

    
    glEnd();


}

void drawText(float x, float y, const char* text) {
    glColor3ub(0, 0, 0);  // Set text color
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(text); i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}



void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to white
    glClear(GL_COLOR_BUFFER_BIT);        // Clear the screen
    circle(19, 45, 23, 0, 0, 0); // Draw the sun
    glLineWidth(5);
    hill();

    glColor3ub(0, 0, 0); // Set text color to black

    // Position adjusted for stroke font
    drawText(20, 7, "  MOUNTAIN");

    glFlush();
}




/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");
    gluOrtho2D(0, 90, -10, 60); // Create a window with the given title
    glutInitWindowSize(750, 900);// Set the window's initial width & height
    glutDisplayFunc(display);// Register display callback handler for window re-paint
    glutIdleFunc(display); // Ensures continuous refresh

    glutMainLoop();           // Enter the event-processing loop
    return 0;
}

