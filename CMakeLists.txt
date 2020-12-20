cmake_minimum_required(VERSION 3.17)

project(snake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/modules/" ${CMAKE_MODULE_PATH})

find_package(Corrade REQUIRED Main)
find_package(Magnum REQUIRED
        GL
        MeshTools
        Primitives
        SceneGraph
        Shaders
        Sdl2Application)

add_executable(snake main.cpp src/snake.cpp src/snake.h)

target_link_libraries(snake PRIVATE
        Corrade::Main
        Magnum::Application
        Magnum::GL
        Magnum::Magnum
        Magnum::MeshTools
        Magnum::Primitives
        Magnum::SceneGraph
        Magnum::Shaders)