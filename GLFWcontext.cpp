#include "GLFWcontext.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>


bool GLFWcontext::m_inited{false};
short GLFWcontext::m_appCount{0};


void GLFWcontext::Init()
{
    ++m_appCount;
    if (!m_inited)
    {
        if (!glfwInit())
        {
            throw std::runtime_error("GLFW said no");
        }
    }
}

void GLFWcontext::setDebugCallback(callback_t debugCallback)
{
    if (m_inited && debugCallback != nullptr)
    {
        glfwSetErrorCallback(debugCallback);
    }
}

void GLFWcontext::Destroy()
{
    --m_appCount;
    if (m_inited && m_appCount == 0)
    {
        glfwTerminate();
    }
}
void GLFWcontext::Terminate()
{
    glfwTerminate();
    throw std::runtime_error("GLFW context was terminated");
}