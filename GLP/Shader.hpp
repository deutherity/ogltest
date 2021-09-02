#pragma once
#include <string>
#include "GLtypes.hpp"


namespace GLP
{
    typedef GLuint shaderId_t;
    typedef GLenum shaderType_t;

    class Shader
    {
    public:

        enum class Status: unsigned char {
            Initialized,
            Read,
            Compiled,
            Empty
        };

        enum class Type: unsigned char {
            Compute,
            Vertex,
            Tess_Control,
            Tess_Eval,
            Geometry,
            Fragment
        };

        constexpr static inline Type toType(const shaderType_t t_type);
        constexpr static inline shaderType_t toGLuint(const Type t_type);
 

    private:
        shaderId_t m_UID;
        std::string m_sourcePath;
        Type m_Type;
        Status m_status = Status::Empty;

    public:

        Shader() = default;
        Shader(const shaderType_t shaderType, std::string&& sourcePath);
        Shader(const Type shaderType, std::string&& sourcePath);
        Shader(const shaderType_t shaderType, const std::string& sourcePath);
        Shader(const Type shaderType, const std::string& sourcePath);

        Shader(Shader&& other);
        Shader(const Shader& other) = delete;
        Shader& operator=(const Shader& other) = delete;
        Shader& operator=(Shader&& other);
        ~Shader();

        shaderId_t getUID() const;
        Type getType() const;
        Status getStatus() const;

        void ReadSource();
        void Compile();
        void doEverything();

    };
   
} // namespace GLP
