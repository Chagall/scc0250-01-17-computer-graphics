#ifndef scene_drawing_h
#define scene_drawing_h

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void drawInitialScene();
void drawRotatedScene(GLfloat angle);
void drawWindvaneTriangles(GLfloat red, GLfloat green, GLfloat blue);
void drawWindvaneStick(GLfloat red, GLfloat green, GLfloat blue, GLfloat height);
void drawCircle(GLfloat red, GLfloat green, GLfloat blue, GLfloat x, GLfloat y, GLfloat radius, GLint numOfPoints);
void rotateWindvaneTriangles(GLfloat angle);



void drawFloor(GLfloat red, GLfloat green, GLfloat blue);
void drawClouds(GLfloat red, GLfloat green, GLfloat blue);
void drawFlyingBirds(GLfloat red, GLfloat green, GLfloat blue);

#endif /* scene_drawing_h */
