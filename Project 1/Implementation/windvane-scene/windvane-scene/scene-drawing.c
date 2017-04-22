/*
    Disciplina: SCC0250 - Computacao Grafica
    Projeto 1 - Cena com Catavento
    Alunos:
    Fabio Alves Martins Pereira     7987435
    Mateus Abrahao Cardoso          8658332
*/

#include "scene-drawing.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>

/*
    Draw Initial Scene
    Função: Desenhar a Cena na tela quando o programa abrir pela primeira vez.
            Nela o catavento não está rotacionado.
*/
void drawInitialScene() {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);                            // Color: Skyblue
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawClouds(1.0f, 1.0f, 1.0f);                                       // Desenha as Nuvens - Color: White
    drawFlyingBirds(0.0f, 0.0f, 0.0f);                                  // Desenha os Pássaros - Color: Black
    drawCircle(1.0f, 1.0f, 0.0f, 5.0f, 190.0f, 20.0f, 100);             // Desenha o Sol - Color: Yellow
    drawFloor(0.0f, 0.78f, 0.34f);                                      // Desenha a Grama - Color: Emerald Green
    drawWindvaneStick(0.80f, 0.68f, 0.49f, 50.0f);                      // Desenha a base do Catavento - Color: Burlywood 3
    drawWindvaneTriangles(0.87f, 0.87f, 0.87f);                         // Desenha a hélice do Catavento - Color: Gray 88
    drawCircle(1.0f, 0.27f, 0.0f, 100.0f, 50.0f, 5.0f, 100);            // Desenha o apoio da Hélice - Color: Orangered
    drawCircle(1.0f, 0.84f, 0.0f, 100.0f, 50.0f, 4.25f, 100);           // Desenha o apoio da Hélice - Color: Gold 1
    
    glFlush();
}

/*
    Draw Rotated Scene
    Função: Desenhar a Cena na tela após algum clique no mouse.
    Nela o catavento está rotacionado no sentido anti-horário ou horário,
    dependendo de qual botão do mouse foi clicado.
    Parametros:
        1 - angle: Angulo de rotacao da helice
*/
void drawRotatedScene(GLfloat angle) {
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);                            // Color: Skyblue
    glClear(GL_COLOR_BUFFER_BIT);
    
    drawClouds(1.0f, 1.0f, 1.0f);                                       // Desenha as Nuvens - Color: White
    drawFlyingBirds(0.0f, 0.0f, 0.0f);                                  // Desenha os Pássaros - Color: Black
    drawCircle(1.0f, 1.0f, 0.0f, 5.0f, 190.0f, 20.0f, 100);             // Desenha o Sol - Color: Yellow
    drawFloor(0.0f, 0.78f, 0.34f);                                      // Desenha a Grama - Color: Emerald Green
    drawWindvaneStick(0.80f, 0.68f, 0.49f, 50.0f);                      // Desenha a base do Catavento - Color: Burlywood 3
    rotateWindvaneTriangles(angle);                                     // Desenha a hélice Rotacionada - Color: Gray 88
    drawCircle(1.0f, 0.27f, 0.0f, 100.0f, 50.0f, 5.0f, 100);            // Desenha o apoio da Hélice - Color: Orangered
    drawCircle(1.0f, 0.84f, 0.0f, 100.0f, 50.0f, 4.25f, 100);           // Desenha o apoio da Hélice - Color: Gold 1
    
    glFlush();
}

/*
    Draw Windvane Triangles
    Função: Desenhar a Hélice do Catavento, composta por 4 triangulos.
    Parametros:
        1, 2, 3 - red, green, blue: Cor da hélice
*/
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

/*
    Draw Windvane Stick
    Função: Desenhar a base do Catavento, composta por um trapézio
    Parametros:
        1, 2, 3 - red, green, blue: Cor da base do Catavento
*/
void drawWindvaneStick(GLfloat red, GLfloat green, GLfloat blue, GLfloat height) {
    glColor3f(red, green, blue);
    
    glBegin(GL_QUADS);
    glVertex2f(90.0f, 2.5f);
    glVertex2f(97.5f, height);
    glVertex2f(102.5f, height);
    glVertex2f(110.0f, 2.5f);
    
    glEnd();
}

/*
    Draw Circle
    Função: Desenhar um circulo na tela
    Parametros:
    1, 2, 3 - red, green, blue: Cor do circulo
    4 - x: posicao do centro do circulo no eixo X
    5 - y: posicao do centro do circulo no eixo Y
    6 - radius: Tamanho do raio do circulo
    7 - numOfPoints: Numero de pontos utilizados para aproximar o formato do circulo
*/
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

/*
    Rotate Windvane Triangles
    Função: Desenhar a Hélice do catavento rotacionada em 'angle' graus
    Parametros:
    1 - angle: Angulo de rotacao da Helice
*/
void rotateWindvaneTriangles(GLfloat angle) {
    glPushMatrix();                 // put current matrix on stack

    glTranslatef(100,50,0.0);       // 3. Translate to the object's position.
    glRotatef(angle,0.0,0.0,1.0);   // 2. Rotate the object.
    glTranslatef(-100,-50,0.0);     // 1. Translate to the origin.
    
    drawWindvaneTriangles(0.87f, 0.87f, 0.87f);
    
    glPopMatrix();
}

/*
    Draw Floor
    Função: Desenhar o chao da Cena
    Parametros:
    1, 2, 3 - red, green, blue: Cor do chao da Cena
*/
void drawFloor(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 5.0f);
    glVertex2f(200.0f, 5.0f);
    glVertex2f(200.0f, 0.0f);
    glEnd();
}

/*
    Draw Clouds
    Função: Desenhar as nuvens da Cena
    Parametros:
    1, 2, 3 - red, green, blue: Cor das nuvens da Cena
*/
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

/*
    Draw Flying Birds
    Função: Desenhar os passaros da Cena
    Parametros:
    1, 2, 3 - red, green, blue: Cor dos passaros da Cena
*/
void drawFlyingBirds(GLfloat red, GLfloat green, GLfloat blue) {
    glColor3f(red, green, blue);
    
    // First Bird
    glBegin(GL_LINES);
    glVertex2f(30.0f, 80.0f);
    glVertex2f(40.0f, 70.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(40.0f, 70.0f);
    glVertex2f(50.0f, 80.0f);
    glEnd();
    
    // Second Bird
    glBegin(GL_LINES);
    glVertex2f(160.0f, 160.0f);
    glVertex2f(170.0f, 150.0f);
    glEnd();
    
    glBegin(GL_LINES);
    glVertex2f(170.0f, 150.0f);
    glVertex2f(180.0f, 160.0f);
    glEnd();
}
