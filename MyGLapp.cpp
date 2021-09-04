#include "MyGLapp.hpp"

#include "GLP/Shader.hpp"
#include "GLP/Program.hpp"
#include "GLP/Buffer.hpp"
#include "GLP/ScopedDebug.hpp"
#include "GLP/IVertexArrayLayout.hpp"
#include "GLP/VertexArray.hpp"
#include "GLP/Renderer.hpp"
#include "GLP/Uniforms/Uniform4f.hpp"
#include "GLP/Uniforms/Uniform1i.hpp"
#include "GLP/Texture.hpp"
#include <GL/glew.h>


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