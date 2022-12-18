#include <GL/glut.h>
#include <math.h>

const double GRAVITY = 9.81; // gravitational acceleration (m/s^2)
const double DT = 0.01; // time step (s)

double x = 0.0; // x position of the sphere (m)
double y = 0.0; // y position of the sphere (m)
double vy = 0.0; // y velocity of the sphere (m/s)

void drawSphere()
{
  // draw the sphere using OpenGL commands
  glColor3f(1.0, 0.0, 0.0);
  glutSolidSphere(0.1, 20, 20);
}

void update()
{
  // update the position and velocity of the sphere
  y += vy * DT;
  vy -= GRAVITY * DT;

  // if the sphere hits the ground, reverse the direction of the velocity
  if (y < 0.0) {
    y = 0.0;
    vy = -vy;
  }
}

void display()
{
  // clear the screen
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // set the camera
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  // draw the sphere
  glPushMatrix();
  glTranslatef(x, y, 0.0);
  drawSphere();
  glPopMatrix();

  // update the screen
  glutSwapBuffers();
}

void timer(int value)
{
  // update the position and velocity of the sphere
  update();

  // redisplay the scene
  glutPostRedisplay();

  // set the timer for the next frame
  glutTimerFunc(1000 * DT, timer, 0);
}

int main(int argc, char **argv)
{
  // initialize GLUT
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Sphere");

  // set up the callbacks
  glutDisplayFunc(display);
  glutTimerFunc(1000 * DT, timer, 0);

  // enter the main loop
  glutMainLoop();
  return 0;
}
