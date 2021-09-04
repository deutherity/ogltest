project(gltest)


set(CMAKE_CXX_FLAGS_RELEASE
    "-DNDEBUG -D'DEBUG_LEVEL=GLP::DEBUG_NONE' -Wall -Wpedantic")

set(CMAKE_CXX_FLAGS_DEBUG
    "-D'DEBUG_LEVEL=GLP::DEBUG_ALL' -g -O0 -Wall -Wpedantic")


set(OpenGL_GL_PREFERENCE "GLVND")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmakeModules")
find_package(OpenGL REQUIRED)
find_package(GLFW3 REQUIRED)
find_package(GLEW REQUIRED)

add_subdirectory("GLP")


set(SOURCES
    "main2.cpp"
    "GLFWapp.cpp"
    "GLFWcontext.cpp"
    "IEntity.cpp"
    "IGLapp.cpp"
    "MyGLapp.cpp"
    "Rectangle.cpp"
)

add_executable(test ${SOURCES})
set_target_properties(test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED TRUE
)


target_include_directories(test PRIVATE 
#${GLEW_INCLUDE_DIRS}
${GLFW3_INCLUDE_PATH} 
#${OPENGL_INCLUDE_DIR}
)

target_link_libraries(test GLP 
OpenGL::GL
${GLFW3_LIBRARY}
GLEW::glew
)
