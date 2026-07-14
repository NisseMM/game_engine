# Game Engine

WORK IN PROGRESS.

A small game engine written in C++20 using OpenGL.

The goal of this project is to learn and explore the architecture and implementation of a game engine, including rendering, window management, and engine systems.

## Features

- C++20 engine architecture
- OpenGL 4.6 rendering
- GLFW window management
- GLAD OpenGL loader
- CMake build system

## Requirements

- C++20 compatible compiler
- CMake 3.20+
- OpenGL 4.6 capable GPU

## Installation of GLFW dependencies
```bash
sudo apt install libwayland-dev libxkbcommon-dev xorg-dev
```

## Building

Clone the repository:
```bash
git clone <repository-url>
cd game_engine
```

Sync submodules:
```bash
git submodule init
git submodule update
```

Configure and build:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

Run:
```bash
./GameEngine
```

## Project Structure
```text
engine/ 
├── include/
│   └── core/
│       └── window.h
├── src/
│   └── core/
│       └── window.cc

sandbox/
└── main.cc

external/
├── glad/
│   └── ...
├── glfw/
│   └── ...
```

## Current Progress

✅ Done
🔄 In progress
⬜ Planned

- ✅ GLFW integration
- ✅ GLAD integration
- ✅ OpenGL context management
- ✅ Window system
- ✅ Time system
- ✅ Buffer abstraction (VAO/VBO/EBO)
- ✅ Vertex layout system
- ✅ Shader system
- ✅ Mesh system
- ✅ OBJ parsing
- ✅ OBJ → Mesh conversion
- 🔄 Renderer implementation
- 🔄 Camera system
- 🔄 Transform system
- 🔄 Application/game loop
- ⬜ Texture system
- ⬜ Material system
- ⬜ Input system
- ⬜ Entity/Component system
- ⬜ Scene management
- ⬜ Animation system