#pragma once
#include "IGLapp.hpp"
#include "GLP/ScopedDebug.hpp"


class MyGLapp: public IGLapp
{

private:
    GLP::ScopedDebug m_debugger;

public:
    MyGLapp();
    ~MyGLapp();
    void updateState() override {};

};
