cmake_minimum_required(VERSION 3.10)
project(RDAlgebra2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} include)

if(MSVC)
    add_compile_options(/W3)
else()
    #    add_compile_options(-Wall -Wpedantic)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

add_executable(RDAlgebra2 main.cpp
        src/math/vec4.cpp
        src/math/grid.cpp
        src/ui/renderer.cpp
        src/ui/scene.cpp
        src/ui/sdl/window.cpp
        src/ui/sdl/frame.cpp
        src/math/mat4.cpp
        src/math/mesh.cpp
        src/game/input_manager.cpp
        src/ui/mesh_loader.cpp
        src/math/complex_mesh.cpp src/game/game_object.cpp src/game/spaceship.cpp include/game/projectile.h)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
