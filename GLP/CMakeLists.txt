cmake_minimum_required(VERSION 3.10)

project(GLP VERSION 1.0.0)

find_package(GLEW REQUIRED)

set( SOURCES 
    "Shader.cpp"
    "Program.cpp"
    "ScopedDebug.cpp"
    "debug.cpp"
    "Buffer.cpp"
    "VertexArray.cpp"
    "Renderer.cpp"
    "IVertexArrayLayout.cpp"
    "Uniform4f.cpp"
    )

add_library(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${GLEW_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} GLEW::glew)

set_target_properties(${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDART_REQUIRED TRUE
)