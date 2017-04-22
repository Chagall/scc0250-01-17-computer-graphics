/*
    Disciplina: SCC0250 - Computacao Grafica
    Projeto 1 - Cena com Catavento
    Alunos:
    Fabio Alves Martins Pereira     7987435
    Mateus Abrahao Cardoso          8658332
*/

#ifndef scene_drawing_h
#define scene_drawing_h

#include <OpenGL/gl.h>

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
