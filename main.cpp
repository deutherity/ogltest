#include "Penguin.hpp"
#include "Rectangle.hpp"
#include "MyGLapp.hpp"
#include "GLFWapp.hpp"


int main(int argc, char const *argv[])
{
    GLFWapp wrapper(1000, 1000, "main");
    MyGLapp app;
    wrapper.assignGLapp(&app);

    Rectangle rectangle;

    Penguin penguin;
    app.addEntity(&rectangle);
    app.addEntity(&penguin);
    
    while (wrapper.frame())
    {
        
    }
    
    return 0;
}
