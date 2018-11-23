cmake_minimum_required(VERSION 3.10)
project(RDAlgebra2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} include)

add_executable(RDAlgebra2 main.cpp src/math/Vector.cpp include/math/Vector.h src/math/Grid.cpp include/math/Grid.h src/ui/Renderer.cpp include/ui/Renderer.h include/ui/Renderable.h src/ui/Scene.cpp include/ui/Scene.h include/ui/VectorRenderable.h src/ui/sdl/Window.cpp include/ui/sdl/Window.h src/ui/sdl/Frame.cpp include/ui/sdl/Frame.h include/ui/GridRenderable.h include/math/Matrix.h src/math/Matrix.cpp include/math/Shape.h src/math/Shape.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
