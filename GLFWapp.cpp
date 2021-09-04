#include "GLFWapp.hpp"
#include "GLFWcontext.hpp"
#include <GLFW/glfw3.h>
#include <cassert>


void glViewport(int, int, int, int);

void windowResizeCallback(GLFWwindow* window, int width, int height)
{
    glfwMakeContextCurrent(window);
    glViewport(0,0,width,height);
}


GLFWapp::GLFWapp(const short width, const short height, std::string_view name)
{
    GLFWcontext::Init();
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(width, height, name.data(), nullptr, nullptr);
    if (m_window == nullptr)
    {
        GLFWcontext::Terminate();
    }

    glfwMakeContextCurrent(m_window);
    glfwSwapInterval(1);
    glfwSetWindowSizeCallback(m_window, windowResizeCallback);
}

GLFWapp::~GLFWapp()
{
    glfwDestroyWindow(m_window);
}

bool GLFWapp::frame()
{
    assert(m_app != nullptr);
    if (glfwWindowShouldClose(m_window))
    {
        return false;
    }
    m_app->frame();
    m_app->draw();
    glfwSwapBuffers(m_window);
    glfwPollEvents();
    return true;
}

void GLFWapp::assignGLapp(IGLapp* app)
{
    m_app = app;
    int width, height;
    glfwGetWindowSize(m_window, &width, &height);
    m_app->resizeEvent(width, height);
}
