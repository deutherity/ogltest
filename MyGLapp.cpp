#include "MyGLapp.hpp"

#include "GLP/ScopedDebug.hpp"


#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL GLP::DEBUG_HIGH
#endif


MyGLapp::MyGLapp():
m_debugger(DEBUG_LEVEL)
{
}

MyGLapp::~MyGLapp()
{

}