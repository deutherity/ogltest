#pragma once
#include <string_view>
#include "IGLapp.hpp"
#include <memory>


struct GLFWwindow;
typedef struct GLFWwindow GLFWwindow;

class GLFWapp
{
private:
    GLFWwindow* m_window;
    IGLapp* m_app;
    
public:
    GLFWapp(const short x, const short y, std::string_view title);
    ~GLFWapp();
    
    void assignGLapp(IGLapp* app);
    bool frame();

};
