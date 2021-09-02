#include "Shader.hpp"
#include <GL/glew.h>
#include <fstream>
#include <utility>
#include <stdexcept>
#include <cassert>


namespace GLP
{
    constexpr inline Shader::Type Shader::toType(const shaderType_t t_type)
    {
        switch (t_type)
        {
        case GL_COMPUTE_SHADER:
            return Type::Compute;
        
        case GL_VERTEX_SHADER:
            return Type::Vertex;
        
        case GL_TESS_CONTROL_SHADER:
            return Type::Tess_Control;
        
        case GL_TESS_EVALUATION_SHADER:
            return Type::Tess_Eval;
        
        case GL_GEOMETRY_SHADER:
            return Type::Geometry;
        
        case GL_FRAGMENT_SHADER:
            return Type::Fragment;

        default:
            throw std::logic_error("This is not a shader type");
        }
    }

    constexpr inline shaderType_t Shader::toGLuint(const Type t_type)
    {
        switch (t_type)
        {
        case Type::Compute:
            return GL_COMPUTE_SHADER;

        case Type::Vertex:
            return GL_VERTEX_SHADER;
            
        case Type::Tess_Control:
            return GL_TESS_CONTROL_SHADER;
            
        case Type::Tess_Eval:
            return GL_TESS_EVALUATION_SHADER;
            
        case Type::Geometry:
            return GL_GEOMETRY_SHADER;

        case Type::Fragment:
            return GL_FRAGMENT_SHADER;

        default:
            throw std::logic_error("This is not a shader type");
        }
    }

    static std::string readSource(const std::string& path)
    {
        std::ifstream fi(path);
        std::string src;

        fi.seekg(0, std::ios::end);   
        src.reserve(fi.tellg());
        fi.seekg(0, std::ios::beg);

        src.assign((std::istreambuf_iterator<char>(fi)),
                std::istreambuf_iterator<char>());
        return src;
    }

    Shader::Shader(const shaderType_t shaderType, const std::string& sourcePath):
    m_UID(glCreateShader(shaderType)), m_sourcePath(sourcePath), m_Type(toType(shaderType)), m_status(Status::Initialized)
    {}

    Shader::Shader(const Type shaderType, const std::string& sourcePath):
    m_UID(glCreateShader(toGLuint(shaderType))), m_sourcePath(sourcePath), m_Type(shaderType), m_status(Status::Initialized)
    {}

    Shader::Shader(const shaderType_t shaderType, std::string&& sourcePath):
    m_UID(glCreateShader(shaderType)), m_sourcePath(std::move(sourcePath)), m_Type(toType(shaderType)), m_status(Status::Initialized)
    {}

    Shader::Shader(const Type shaderType, std::string&& sourcePath):
    m_UID(glCreateShader(toGLuint(shaderType))), m_sourcePath(std::move(sourcePath)), m_Type(shaderType), m_status(Status::Initialized)
    {}

    Shader::Shader(Shader&& other):
    m_UID(other.m_UID), m_sourcePath(std::move(other.m_sourcePath)), m_status(other.m_status), m_Type(other.m_Type)
    {
        other.m_status = Status::Empty;
    }

    Shader& Shader::operator=(Shader&& other)
    {
        assert(m_status == Status::Empty);
        m_UID = other.m_UID;
        m_status = other.m_status;
        m_Type = other.m_Type;
        m_sourcePath = std::move(other.m_sourcePath);
        other.m_status = Status::Empty;
        return *this;
    }

    Shader::~Shader()
    {
        glDeleteShader(m_UID);
    }

    void Shader::ReadSource()
    {
        if (m_status != Shader::Status::Initialized)
        {
            throw std::logic_error("Shader source is already loaded: " + m_sourcePath);
        }
        std::string src = readSource(m_sourcePath);
        const char * c_src = src.c_str();
        glShaderSource(m_UID, 1, &c_src, nullptr);

        m_status = Shader::Status::Read;
    }

    void Shader::Compile()
    {
        if (m_status != Shader::Status::Read)
        {
            throw std::logic_error("Shader either already compiled or not read: " + m_sourcePath);
        }

        glCompileShader(m_UID);

        int res;
        glGetShaderiv(m_UID, GL_COMPILE_STATUS, &res);

        if (!res)
        {
            int leng;
            glGetShaderiv(m_UID, GL_INFO_LOG_LENGTH, &leng);
            char * message = new char[leng];
            glGetShaderInfoLog(m_UID, leng, &leng, message);
            throw std::runtime_error("Failed to compile shader: " + m_sourcePath + '\n' + message);
        }

        m_status = Shader::Status::Compiled;
    }
    
    void Shader::doEverything()
    {
        this->ReadSource();
        this->Compile();
    }

    shaderId_t Shader::getUID() const
    {
        return m_UID;
    }

    Shader::Type Shader::getType() const
    {
        return m_Type;
    }

    Shader::Status Shader::getStatus() const
    {
        return m_status;
    }
} // namespace GLP
