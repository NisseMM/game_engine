cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/glfw)

add_library(glad
    external/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

add_library(engine
    engine/src/core/window.cc
    engine/src/context/openglcontext.cc
)

target_include_directories(engine PUBLIC
    engine/include
)

target_link_libraries(engine PUBLIC
    glfw
    glad
    dl
)

add_executable(GameEngine
    sandbox/main.cc
)

target_link_libraries(GameEngine
    engine
)
