#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

//outline circle
void Circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_LINE_LOOP);// Draw a Red 1x1 Square centered at origin
    for (int i = 0;i < 200;i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}
// Function to draw a filled circle
void circle11(float radius, float xc, float yc, float r, float g, float b) {
    glBegin(GL_POLYGON);
    glColor3f(r, g, b);
    for (int i = 0; i < 200; i++) {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float x = radius * cos(A);
        float y = radius * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}
/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
    glLineWidth(5);


    circle11(5.0f, -2.0f, 2.0f, 0.8f, 0.93f, 1.0f); // Top-left circle
    circle11(5.0f, 2.0f, 2.0f, 0.8f, 0.93f, 1.0f);  // Top-right circle
    circle11(5.0f, -2.0f, -2.0f, 0.8f, 0.93f, 1.0f); // Bottom-left circle
    circle11(5.0f, 2.0f, -2.0f, 0.8f, 0.93f, 1.0f);  // Bottom-right circle
    //Up arrow

    glBegin(GL_POLYGON);
    glColor3ub(255, 79, 0);
    glVertex2f(0.11387, 3.56938);
    glVertex2f(1.77202, 1.68163);
    glVertex2f(-1.49327, 1.68163);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(255, 79, 0);
    glVertex2f(0.87917, 1.83061);
    glVertex2f(0.8386, 0.43812);
    glVertex2f(-0.54073, 0.45478);
    glVertex2f(-0.52388, 1.83061);
    glEnd();





    //Middle Circle
    circle(1.54, 0.16, -0.89, 0, 255, 255);
    circle(0.81, 0.16, -0.89, 255, 255, 255);
    Circle(0.81, 0.16, -0.89, 0, 139, 139);

    //left box
    glColor3ub(255, 204, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.77289, -0.71909);
    glVertex2f(-1.77289, -1.04944);
    glVertex2f(-2.24658, -1.08635);
    glVertex2f(-2.2474, -0.73623);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-2.2474, -0.73623);
    glVertex2f(-2.23523, -3.92278);
    glVertex2f(-2.63381, -3.90923);
    glVertex2f(-2.61628, -0.76177);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(-1.59949, -3.32278);
    glVertex2f(-1.60163, -5.10082);
    glVertex2f(-3.28048, -5.04752);
    glVertex2f(-3.29101, -3.35684);
    glEnd();




    //Middle box
    glColor3ub(255, 204, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.31584, -2.80999);
    glVertex2f(0.35938, -3.94188);
    glVertex2f(-0.02501, -3.9354);
    glVertex2f(-0.01444, -2.80999);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.99066, -3.35914);
    glVertex2f(0.96909, -5.10627);
    glVertex2f(-0.69558, -5.06084);
    glVertex2f(-0.67739, -3.35195);
    glEnd();



    //right box

    glColor3ub(255, 204, 0);
    glBegin(GL_POLYGON);
    glVertex2f(2.0669, -0.71234);
    glVertex2f(2.94994, -0.74008);
    glVertex2f(2.96745, -1.08264);
    glVertex2f(2.08206, -1.05061);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(2.94994, -0.74008);
    glVertex2f(2.94213, -3.52186);
    glVertex2f(2.58175, -3.52186);
    glVertex2f(2.56664, -1.07575);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(3.65473, -3.35552);
    glVertex2f(3.64116, -5.10765);
    glVertex2f(1.85261, -5.13129);
    glVertex2f(1.8673, -3.34828);
    glEnd();





    //Teeth
    glColor3ub(0, 255, 255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.54073, 0.45478);
    glVertex2f(-0.88249, 0.70902);
    glVertex2f(-1.42799, 0.16301);
    glVertex2f(-1.13673, -0.18291);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.26157, -0.43611);
    glVertex2f(-1.71646, -0.50823);
    glVertex2f(-1.71217, -1.30586);
    glVertex2f(-1.21502, -1.31861);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-1.14561, -1.57142);
    glVertex2f(-1.44254, -1.93038);
    glVertex2f(-0.91198, -2.45093);
    glVertex2f(-0.54158, -2.21068);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.31133, -2.26073);
    glVertex2f(-0.23125, -2.73123);
    glVertex2f(0.57962, -2.75125);
    glVertex2f(0.57962, -2.32079);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.85991, -2.16062);
    glVertex2f(1.20028, -2.49097);
    glVertex2f(1.74085, -1.97042);
    glVertex2f(1.4788, -1.56473);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(1.57666, -1.32009);
    glVertex2f(2.00073, -1.28265);
    glVertex2f(2.01852, -0.49204);
    glVertex2f(1.59187, -0.44366);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(1.47751, -0.16655);
    glVertex2f(1.77218, 0.13912);
    glVertex2f(1.19601, 0.69994);
    glVertex2f(0.8386, 0.43812);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(0.60662, 0.55919);
    glVertex2f(0.51865, 0.99464);
    glVertex2f(-0.23349, 0.98145);
    glVertex2f(-0.27308, 0.5372);
    glEnd();





    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(620, 620);// Set the window's initial width & height// Initialize GLUT
    glutCreateWindow("OpenGL Setup Test");
    gluOrtho2D(-9, 9, -9, 9); // Create a window with the given title

    glutDisplayFunc(display);// Register display callback handler for window re-paint
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
