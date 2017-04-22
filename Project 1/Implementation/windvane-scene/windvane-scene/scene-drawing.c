#include "scene-drawing.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>

void drawInitialScene() {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);                            // Color: Skyblue
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawClouds(1.0f, 1.0f, 1.0f);                                       // Color: White
    drawFlyingBirds(0.0f, 0.0f, 0.0f);                                  // Color: Black
    drawCircle(1.0f, 1.0f, 0.0f, 5.0f, 190.0f, 20.0f, 100);             // Color: Yellow
    drawFloor(0.0f, 0.78f, 0.34f);                                      // Color: Emerald Green
    drawWindvaneStick(0.80f, 0.68f, 0.49f, 50.0f);                      // Color: Burlywood 3
    drawWindvaneTriangles(0.87f, 0.87f, 0.87f);                         // Color: Gray 88
    drawCircle(1.0f, 0.27f, 0.0f, 100.0f, 50.0f, 5.0f, 100);            // Color: Orangered
    drawCircle(1.0f, 0.84f, 0.0f, 100.0f, 50.0f, 4.25f, 100);           // Color: Gold 1
    
    glFlush();
}

void drawRotatedScene(GLfloat angle) {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);                            // Color: Skyblue
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawClouds(1.0f, 1.0f, 1.0f);                                       // Color: White
    drawFlyingBirds(0.0f, 0.0f, 0.0f);                                  // Color: Black
    drawCircle(1.0f, 1.0f, 0.0f, 5.0f, 190.0f, 20.0f, 100);             // Color: Yellow
    drawFloor(0.0f, 0.78f, 0.34f);                                      // Color: Emerald Green
    drawWindvaneStick(0.80f, 0.68f, 0.49f, 50.0f);                      // Color: Burlywood 3
    rotateWindvaneTriangles(angle);                                     // Color: Squi Gray 72
    drawCircle(1.0f, 0.27f, 0.0f, 100.0f, 50.0f, 5.0f, 100);            // Color: Orangered
    drawCircle(1.0f, 0.84f, 0.0f, 100.0f, 50.0f, 4.25f, 100);           // Color: Gold 1
    
    glFlush();
}

void drawWindvaneTriangles(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(90.0f, 80.0f);
    glVertex2f(110.0f, 80.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(130.0f, 40.0f);
    glVertex2f(130.0f, 60.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(90.0f, 20.0f);
    glVertex2f(110.0f, 20.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(100.0f, 50.0f);
    glVertex2f(70.0f, 40.0f);
    glVertex2f(70.0f, 60.0f);
    glEnd();
}

void drawWindvaneStick(GLfloat red, GLfloat green, GLfloat blue, GLfloat height) {
    glColor3f(red, green, blue);
    
    glBegin(GL_QUADS);
    glVertex2f(90.0f, 2.5f);
    glVertex2f(97.5f, height);
    glVertex2f(102.5f, height);
    glVertex2f(110.0f, 2.5f);
    
    glEnd();
}

void drawCircle(GLfloat red, GLfloat green, GLfloat blue, GLfloat x, GLfloat y, GLfloat radius, GLint numOfPoints) {
    glColor3f(red, green, blue);
    
    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    
    GLfloat angle = (2.0f * 3.1416f) / numOfPoints;
    GLfloat angle1 = 0.0;
    
    glBegin(GL_POLYGON);
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    
    for (int i = 0; i < numOfPoints; i++){
        glVertex2d(radius * cos(angle1), radius *sin(angle1));
        angle1 += angle;
    }
    
    glEnd();
    glPopMatrix();
}

void rotateWindvaneTriangles(GLfloat angle) {
    glPushMatrix(); // put current matrix on stack

    glTranslatef(100,50,0.0); // 3. Translate to the object's position.
    glRotatef(angle,0.0,0.0,1.0);   // 2. Rotate the object.
    glTranslatef(-100,-50,0.0); // 1. Translate to the origin.
    
    drawWindvaneTriangles(0.87f, 0.87f, 0.87f);
    
    glPopMatrix();

}

void drawFloor(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(200.0f, 5.0f);
    glVertex2f(200.0f, 0.0f);
    glEnd();
}

void drawClouds(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    // Upper Clouds 1
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 120.0f);
    glVertex2f(30.0f, 120.0f);
    glVertex2f(20.0f, 130.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(30.0f, 120.0f);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(40.0f, 130.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(70.0f, 120.0f);
    glVertex2f(60.0f, 130.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(20.0f, 120.0f);
    glVertex2f(40.0f, 120.0f);
    glVertex2f(30.0f, 130.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(40.0f, 120.0f);
    glVertex2f(60.0f, 120.0f);
    glVertex2f(50.0f, 130.0f);
    glEnd();
    
    
    // Down Clouds 1
    glBegin(GL_TRIANGLES);
    glVertex2f(10.0f, 120.0f);
    glVertex2f(30.0f, 120.0f);
    glVertex2f(20.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(30.0f, 120.0f);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(40.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(50.0f, 120.0f);
    glVertex2f(70.0f, 120.0f);
    glVertex2f(60.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(20.0f, 120.0f);
    glVertex2f(40.0f, 120.0f);
    glVertex2f(30.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(40.0f, 120.0f);
    glVertex2f(60.0f, 120.0f);
    glVertex2f(50.0f, 110.0f);
    glEnd();
    
  
    // Upper Clouds 2
    glBegin(GL_TRIANGLES);
    glVertex2f(130.0f, 100.0f);
    glVertex2f(150.0f, 100.0f);
    glVertex2f(140.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(150.0f, 100.0f);
    glVertex2f(170.0f, 100.0f);
    glVertex2f(160.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(170.0f, 100.0f);
    glVertex2f(190.0f, 100.0f);
    glVertex2f(180.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(140.0f, 100.0f);
    glVertex2f(160.0f, 100.0f);
    glVertex2f(150.0f, 110.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(160.0f, 100.0f);
    glVertex2f(180.0f, 100.0f);
    glVertex2f(170.0f, 110.0f);
    glEnd();
    
    // Down Clouds 2
    glBegin(GL_TRIANGLES);
    glVertex2f(130.0f, 100.0f);
    glVertex2f(150.0f, 100.0f);
    glVertex2f(140.0f, 90.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(150.0f, 100.0f);
    glVertex2f(170.0f, 100.0f);
    glVertex2f(160.0f, 90.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(170.0f, 100.0f);
    glVertex2f(190.0f, 100.0f);
    glVertex2f(180.0f, 90.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(140.0f, 100.0f);
    glVertex2f(160.0f, 100.0f);
    glVertex2f(150.0f, 90.0f);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2f(160.0f, 100.0f);
    glVertex2f(180.0f, 100.0f);
    glVertex2f(170.0f, 90.0f);
    glEnd();
}

void drawFlyingBirds(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    glBegin(GL_LINES);
    glVertex2f(30.0f, 80.0f);
    glVertex2f(40.0f, 70.0f);
    glEnd();
    
    glColor3f(red, green, blue);
    
    glBegin(GL_LINES);
    glVertex2f(40.0f, 70.0f);
    glVertex2f(50.0f, 80.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(160.0f, 160.0f);
    glVertex2f(170.0f, 150.0f);
    glEnd();
    
    glColor3f(red, green, blue);
    
    glBegin(GL_LINES);
    glVertex2f(170.0f, 150.0f);
    glVertex2f(180.0f, 160.0f);
    glEnd();
    
}
