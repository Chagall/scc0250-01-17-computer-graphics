/*
    Disciplina: SCC0250 - Computacao Grafica
    Projeto 1 - Cena com Catavento
    Alunos:
    Fabio Alves Martins Pereira     7987435
    Mateus Abrahao Cardoso          8658332
    Gabriel Zovaro Nacimento
*/

#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "mouse-events.h"
#include "scene-drawing.h"

// Angulo de rotacao da Helice do Catavento
GLfloat ROTATE_ANGLE = 0.0f;

/*
    Handle Mouse Click
    Função: Tratar o clique do mouse. Se o clique for do botao esquerdo, rotacionar
            a helice no sentido anti-horario, se o clique for do botao direito, rotacionar
            a helice no sentido horario.
    Parametros:
        1 - whichButton: Qual botao do mouse foi clicado
        2 - buttonState: Estado do botao
        3 - posX: Posicao do mouse no eixo X (Nao Utilizado)
        4 - posX: Posicao do mouse no eixo Y (Nao Utilizado)
*/
void handleMouseClick(GLint whichButton, GLint buttonState, GLint posX, GLint posY){
    if(GLUT_LEFT_BUTTON == whichButton && GLUT_DOWN == buttonState){
        ROTATE_ANGLE += 36.0f;
        drawRotatedScene(ROTATE_ANGLE);
    }
    else if(GLUT_RIGHT_BUTTON == whichButton && GLUT_DOWN == buttonState){
        ROTATE_ANGLE -= 36.0f;
        drawRotatedScene(ROTATE_ANGLE);
    }
}
