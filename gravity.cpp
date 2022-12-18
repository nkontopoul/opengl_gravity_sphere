#include <GL/glut.h>
#include <cmath>

const float GRAVITY = 9.81; // gravitational acceleration (m/s^2)
const float MASS = 1.0; // mass of the sphere (kg)
const float RADIUS = 0.1; // radius of the sphere (m)
const float DT = 0.01; // time step (s)

// position and velocity of the sphere
float x = 0.0;
float y = 0.0;
float vx = 0.0;
float vy = 0.0;

void display()
{
    // clear the screen
    glClear(GL_COLOR_BUFFER_BIT);

    // draw the sphere
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(RADIUS, 20, 20);

    // move the sphere
    x += vx * DT;
    y += vy * DT;
    vy -= GRAVITY * DT; // apply gravity

    // check if the sphere has reached the ground
    if (y < RADIUS)
    {
        y = RADIUS;
        vy = -vy * 0.8; // apply elastic collision with the ground
    }

    // update the view
    glLoadIdentity();
    glTranslatef(x, y, 0.0);
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // initialize OpenGL
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Sphere");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    // set the display function
    glutDisplayFunc(display);

    // start the main loop
    glutMainLoop();
    return 0;
}
