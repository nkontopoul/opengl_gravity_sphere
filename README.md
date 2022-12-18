# opengl_gravity_sphere
simple example of how you can implement a sphere moving upwards with gravity in C++ using OpenGL

This code uses GLUT (the OpenGL Utility Toolkit) to create a window and draw the sphere. The sphere is moved by updating its position and velocity based on the gravitational acceleration and the time step (DT). The sphere is also drawn at the new position after each update.

To make the sphere move downwards with gravity, you can simply change the sign of the gravitational acceleration and the initial velocity of the sphere. For example:
const float GRAVITY = -9.81; // gravitational acceleration (m/s^2)
// ...
float vy = 10.0; // initial velocity (m/s)
