#include "Rectangle.hpp"
#include "MyGLapp.hpp"
#include "GLFWapp.hpp"


int main(int argc, char const *argv[])
{
    GLFWapp wrapper(1000, 1000, "main");
    MyGLapp app;
    wrapper.assignGLapp(&app);
    Rectangle rect;
    app.addEntity(&rect);
    
    while (wrapper.frame())
    {
        
    }
    
    return 0;
}
