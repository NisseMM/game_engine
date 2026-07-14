cmake_minimum_required(VERSION 3.20)

project(GameEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(external/glfw)
add_subdirectory(external/glm)

add_library(glad
    external/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

add_library(engine
    engine/src/core/window.cc
    engine/src/core/time.cc
    engine/src/context/openglcontext.cc
    engine/src/rendering/renderer.cc
    engine/src/rendering/shader.cc
    engine/src/rendering/vertex_array.cc
    engine/src/rendering/vertex_buffer.cc
    engine/src/rendering/vertex_layout.cc
    engine/src/rendering/index_buffer.cc
    engine/src/rendering/mesh.cc
    engine/src/scene/transform.cc
    engine/src/scene/camera.cc
    engine/src/asset/model_loader.cc
)

target_include_directories(engine PUBLIC
    engine/include
)

target_link_libraries(engine PUBLIC
    glfw
    glad
    glm::glm
)

if(UNIX AND NOT APPLE)
    target_link_libraries(engine PRIVATE dl)
endif()

add_executable(GameEngine
    sandbox/main.cc
)

target_link_libraries(GameEngine PRIVATE
    engine
)
