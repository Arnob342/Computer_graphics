#include <GL/glut.h>

const int boardSize = 4;
const float squareSize = 0.5f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if ((row + col) % 2 == 0)
                glColor3f(1.0f, 1.0f, 1.0f);
            else
                glColor3f(0.0f, 0.0f, 0.0f);

            float x = col * squareSize - 1.0f;
            float y = row * squareSize - 1.0f;

            glBegin(GL_QUADS);
            glVertex2f(x, y);
            glVertex2f(x + squareSize, y);
            glVertex2f(x + squareSize, y + squareSize);
            glVertex2f(x, y + squareSize);
            glEnd();
        }
    }

    glFlush();
}

void init()
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("4x4 Chess Board");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
