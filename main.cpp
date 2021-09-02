#include <GL/glew.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <GLFW/glfw3.h>
#include "cassert"
#include <cmath>
#include "GLP/Shader.hpp"
#include "GLP/Program.hpp"
#include "GLP/Buffer.hpp"
#include "GLP/ScopedDebug.hpp"
#include "GLP/IVertexArrayLayout.hpp"
#include "GLP/VertexArray.hpp"
#include "GLP/Renderer.hpp"
#include "GLP/Uniform4f.hpp"

typedef unsigned int uint;
static constexpr float pi = 3.14159f;


void windowResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0,width,height);
} 


struct posit_t
{
    char pad;
    float x;
    float y;
};

class PositLayout: public GLP::IVertexArrayLayout
{
public:
    PositLayout(std::size_t t_size):
    IVertexArrayLayout(t_size)
    {}
    void setVertexInfo() const override
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(posit_t), (const void*) offsetof(posit_t, x) );
        glEnableVertexAttribArray(0);
    }
};

class PositLayout2: public GLP::IVertexArrayLayout
{
public:
    PositLayout2(std::size_t t_size):
    IVertexArrayLayout(t_size)
    {}
    void setVertexInfo() const override
    {
        glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*) 0 );
        glEnableVertexAttribArray(0);
    }
};

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetWindowSizeCallback(window, windowResizeCallback);

    glfwSwapInterval(1);

    if (GLEW_OK != glewInit())
        return 1;
    
    GLP::ScopedDebug debugger(GLP::DEBUG_ALL);
    std::cout << glGetString(GL_VERSION) << std::endl;

    posit_t pos[] = {
        {'a', 1.0, 1.0},
        {'1', 1.0, 1.0},
        {'2', 1.0, 1.0},
        {'3', 1.0, 1.0}
    }; 

    float pos_[] = {
    -0.5f, -0.5f,
     0.5f, -0.5f,
     0.5f, 0.5f,
    -0.5f, 0.5f
    
    };

    uint ind[] = {
        0,1,2,
        0,2,3
    };



    GLP::Buffer vertBuf(GLP::Buffer::Type::Array, sizeof(pos_), pos_);
    GLP::Buffer indBuf(GLP::Buffer::Type::ElementArray, sizeof(ind), ind);
    PositLayout2 info(sizeof(ind) / sizeof(uint));

    GLP::VertexArray vao(&vertBuf, &info, &indBuf);
    vao.Unbind();



    GLP::Shader frag(GLP::Shader::Type::Fragment, std::string("./src/shaders/frag.fs"));
    frag.doEverything();
    GLP::Shader vert(GLP::Shader::Type::Vertex, std::string("./src/shaders/vert.vs"));
    vert.doEverything();

    GLP::Program prog;

    prog.AttachShader(&frag);
    prog.AttachShader(&vert);

    prog.Link();

    GLP::Uniform4f u_Color(prog, "u_Color");

 
    GLP::Renderer rend;

    rend.SetShader(prog);

    float time = 0.0f;
    float incr = 0.01f;
    vertBuf.Bind();
    indBuf.Bind();
    int i = 0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window) && i < 100)
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        if (time >= pi && incr > 0)
            incr = -0.01f;
        if (time <= 0 && incr < 0)
            incr = 0.01f;
        time += incr;

        u_Color.setValue(std::sin(time), 1.0f, 0.0f, 1.0f);
        vao.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        //rend.Draw(vao);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }
    std::cout << std::endl;


    glfwTerminate();
    return 0;
}