/*
    Disciplina: SCC0250 - Computacao Grafica
    Projeto 1 - Cena com Catavento
    Alunos:
    Fabio Alves Martins Pereira     7987435
    Mateus Abrahao Cardoso          8658332
    Gabriel Zovaro Nacimento
 */

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "mouse-events.h"
#include "scene-drawing.h"

// --- Prototipos das funcoes utilizadas pelo programa ---


// ---------------------- Main -----------------------
int main(int argc, char * argv[]) {
    
    const char* windowTitle = "Cena Catavento";
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(-1, -1);
    glutCreateWindow(windowTitle);
    
    glutDisplayFunc(drawInitialScene);
    glutMouseFunc(handleMouseClick);
    
    glMatrixMode(GL_PROJECTION);    // Inicia-se a matriz de transformacoes da openGL
    gluOrtho2D(0, 200, 0, 200);     // Ordem dos parametros: left, right, bottom, top

    glutMainLoop();
    
    return 0;
    
}
















