cmake_minimum_required(VERSION 3.10)

project(GLP VERSION 1.0.0)

find_package(GLEW REQUIRED)

set(CMAKE_CXX_FLAGS_RELEASE
    "-DNDEBUG -D'DEBUG_LEVEL=GLP::DEBUG_NONE' -Wall -Wpedantic")

set(CMAKE_CXX_FLAGS_DEBUG
    "-D'DEBUG_LEVEL=GLP::DEBUG_ALL' -g -O0 -Wall -Wpedantic")


set( SOURCES 
    "Shader.cpp"
    "Program.cpp"
    "ScopedDebug.cpp"
    "debug.cpp"
    "Buffer.cpp"
    "VertexArray.cpp"
    "Renderer.cpp"
    "IVertexArrayLayout.cpp"
    "Uniforms/Uniform4f.cpp"
    "Uniforms/Uniform1i.cpp"
    "Uniforms/IUniform.cpp"
    "Texture.cpp"
    "stb_image.c"
    )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR} "${CMAKE_CURRENT_LIST_DIR}/Uniforms" )
target_include_directories(${PROJECT_NAME} PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} GLEW::glew)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDART_REQUIRED TRUE
)