
#include <windows.h>
#include <GL/glut.h>
#include <math.h>


// Enum for scene selection
enum Scene {
    SUNNY_CAR,
    STORMY_SHIP
};

Scene currentScene = SUNNY_CAR; // Start with the sunny car scene

// Function to set up projection for the current scene
void setProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (currentScene == SUNNY_CAR) {
        gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Ortho for sunny car
    } else if (currentScene == STORMY_SHIP) {
        gluOrtho2D(-2.0, 2.0, -1.5, 1.5); // Ortho for stormy ship
    }
    glMatrixMode(GL_MODELVIEW);
}

// Function to draw the car in the sunny day scene
void drawSunnyCarScene() {
    // Background: Sky
    glColor3f(0.5f, 0.8f, 1.0f); // Sky blue
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Ground
    glColor3f(0.3f, 0.7f, 0.3f); // Green
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.5f);
        glVertex2f(1.0f, -0.5f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Car body
    glColor3f(1.0f, 0.0f, 0.0f); // Red car
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.6f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(0.3f, -0.4f);
        glVertex2f(-0.3f, -0.4f);
    glEnd();

    // Car roof
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.4f);
        glVertex2f(0.2f, -0.4f);
        glVertex2f(0.15f, -0.3f);
        glVertex2f(-0.15f, -0.3f);
    glEnd();

    // Wheels
    glColor3f(0.0f, 0.0f, 0.0f); // Black wheels
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180;
        glVertex2f(-0.2f + 0.05f * cos(theta), -0.7f + 0.05f * sin(theta));
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++) {
        float theta = i * 3.14159f / 180;
        glVertex2f(0.2f + 0.05f * cos(theta), -0.7f + 0.05f * sin(theta));
    }
    glEnd();
}

// Function to draw the ship in the stormy day scene
void drawStormyShipScene() {
    // Background: Dark sky
    glColor3f(0.2f, 0.2f, 0.3f); // Dark blue-gray
    glBegin(GL_QUADS);
        glVertex2f(-2.0f, -1.5f);
        glVertex2f(2.0f, -1.5f);
        glVertex2f(2.0f, 1.5f);
        glVertex2f(-2.0f, 1.5f);
    glEnd();

    // Water
    glColor3f(0.0f, 0.0f, 0.5f); // Dark blue
    glBegin(GL_QUADS);
        glVertex2f(-2.0f, -0.2f);
        glVertex2f(2.0f, -0.2f);
        glVertex2f(2.0f, -1.5f);
        glVertex2f(-2.0f, -1.5f);
    glEnd();

    // Ship body
    glColor3f(0.4f, 0.2f, 0.0f); // Brown
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f(0.4f, -0.4f);
        glVertex2f(0.3f, -0.6f);
        glVertex2f(-0.3f, -0.6f);
    glEnd();

    // Ship mast
    glColor3f(0.5f, 0.3f, 0.1f); // Lighter brown
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.4f);
        glVertex2f(0.05f, -0.4f);
        glVertex2f(0.05f, 0.3f);
        glVertex2f(-0.05f, 0.3f);
    glEnd();

    // Ship sail
    glColor3f(1.0f, 1.0f, 1.0f); // White
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.05f, 0.3f);
        glVertex2f(0.3f, 0.0f);
        glVertex2f(-0.05f, 0.0f);
    glEnd();
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    setProjection(); // Set the correct projection for the current scene

    if (currentScene == SUNNY_CAR) {
        drawSunnyCarScene();
    } else if (currentScene == STORMY_SHIP) {
        drawStormyShipScene();
    }

    glutSwapBuffers();
}

// Handle keyboard input to switch between scenes
void keyboard(unsigned char key, int x, int y) {
    if (key == '1') {
        currentScene = SUNNY_CAR;
    } else if (key == '2') {
        currentScene = STORMY_SHIP;
    }
    glutPostRedisplay();
}

// Initialize OpenGL
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car and Ship Scenes with Different Projections");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
