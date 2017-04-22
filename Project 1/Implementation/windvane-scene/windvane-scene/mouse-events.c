#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include "mouse-events.h"
#include "scene-drawing.h"

GLfloat ROTATE_ANGLE = 0.0f;

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
