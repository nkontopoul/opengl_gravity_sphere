 OpenGL program in C++ that draws a red sphere and animates it moving upwards with gravitational acceleration and then downwards with gravity
 sphere gains energy in each bounch simulating reverse entropy.
 The program uses the GLUT library to handle the windowing and rendering. The drawSphere function draws a red sphere using OpenGL commands. The update function updates the position and velocity of the sphere based on the gravitational acceleration and the time step. The display function draws the scene by clearing the screen, setting the camera, and drawing the sphere. The timer function updates the position and velocity of the sphere and redisplays the scene at a fixed frame rate.
Tested in visual studio 2022/c++ with GLEW/GLUT
