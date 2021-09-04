#pragma once
#include <memory>

typedef void (*callback_t)(int, const char*);


class GLFWcontext
{
private:
    static bool m_inited;
    static short m_appCount;  // kinda dumb but whatever

public:
    GLFWcontext() = delete;
    static void Init();
    static void setDebugCallback(callback_t debugCallback);
    static void Destroy();
    static void Terminate();
};

