#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glew.h"
#include "OGLapp.hpp"


    // initializes openGL in SDLapp
void OGLapp::init(const int width, const int height)
    {
        glViewport(0,0, width, height);

        glGenBuffers(1, &(this->VAOid));
        glBindVertexArray(VertexArrayID);
    }

    // renders frames in cycle()
void OGLapp::frame()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

void OGLapp::destroy()
    {
        
    }




