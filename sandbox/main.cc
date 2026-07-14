#include <core/window.h>
#include <core/time.h>
#include <rendering/renderer.h>
#include <rendering/shader.h>
#include <rendering/vertex_array.h>
#include <rendering/vertex_buffer.h>
#include <rendering/vertex_layout.h>
#include <rendering/index_buffer.h>
#include <scene/transform.h>
#include <scene/camera.h>
#include <rendering/mesh.h>
#include <asset/model_loader.h>

#include <iostream>
#include <chrono>
#include <thread>

#include <math/math.h>

int main()
{
    Window window{
        1280,
        720,
        "Engine",
        true};

    window.makeContextCurrent();
    Renderer renderer{Color{1.0, 0.0, 1.0, 1.0}};

    ShaderProgram shader{ShaderStage{"assets/shaders/basic.frag", ShaderType::FRAG}, ShaderStage{"assets/shaders/basic.vert", ShaderType::VERT}};

    ModelLoader loader{};
    loader.load("assets/objects/utah_teapot.obj");

    Mesh mesh{loader.createMesh()};

    Transform teapot_transform{};
    teapot_transform.translate({0.0f, 0.0f, 0.0f});

    Camera camera{45.0f,
                  1280.0f / 720.0f,
                  0.1f,
                  100.0f};
    camera.transform().translate({0.0f, 15.0f, 25.0f});
    camera.transform().rotate({-25.0f, 0.0f, 0.0f});
    Time time{};
    time.setFps(360);
    float SECONDS_PER_UPDATE{1 / 144.0};
    teapot_transform.rotate({270.0f, 0.0f, 0.0f});

    float lag{0.0f};
    while (not window.shouldClose())
    {
        time.beginFrame();
        float delta = time.deltaTime();
        lag += delta;

        while (lag >= SECONDS_PER_UPDATE)
        {
            //update
            teapot_transform.rotate({0.0f, 0.0f, 1.0f});

            lag -= SECONDS_PER_UPDATE;
        }

        renderer.beginFrame(window);
        renderer.draw(mesh, teapot_transform, camera, shader);
        window.update();
        time.endFrame();
    }
}