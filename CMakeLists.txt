cmake_minimum_required(VERSION 3.10)
project(RDAlgebra2)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(SDL2_PATH "C:/SDL2")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} include)

add_executable(RDAlgebra2 main.cpp src/math/vector.cpp include/math/vector.h src/math/grid.cpp include/math/grid.h src/ui/renderer.cpp include/ui/renderer.h include/ui/renderable.h src/ui/scene.cpp include/ui/scene.h include/ui/vector_renderable.h src/ui/sdl/window.cpp include/ui/sdl/window.h src/ui/sdl/frame.cpp include/ui/sdl/frame.h include/ui/grid_renderable.h include/math/mat4.h src/math/mat4.cpp include/math/shape.h src/math/shape.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} ${SDL2_LIBRARY})
