#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/Window.h>
#include <ui/Renderer.h>
#include <math/Vector.h>
#include <math/Grid.h>
#include <math/Matrix.h>
#include <math/Shape.h>

#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <windows.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

using namespace ui;
using namespace math;
using namespace ui::sdl;

int main(int argc, char *argv[]) {

    AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long) handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    ui::sdl::Window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    Renderer renderer{window};
    Scene scene{};

    math::Matrix matrix{3, 3, 1.f};
    auto vectorTranslate = math::Vector{20.f, 20.f};
    matrix.translate(vectorTranslate);

    auto vectorScale = math::Vector{10.f, 10.f};
    matrix.scale(vectorScale);

    math::Vector vector1{-4, -4, 1};
    math::Vector vector2{4, -4, 1};
    math::Vector vector3{4, 4, 1};
    math::Vector vector4{-4, 4, 1};
    math::Vector vector5{-4, -4, 1};

    Shape shape;
    shape.points.push_back(vector1);
    shape.points.push_back(vector2);
    shape.points.push_back(vector3);
    shape.points.push_back(vector4);
    shape.points.push_back(vector5);

    shape.multiply(matrix);

    Grid grid{};

    scene.renderables.push_back(dynamic_cast<Renderable*>(&shape));
    scene.renderables.push_back(dynamic_cast<Renderable*>(&grid));

    while(!window.shouldClose()) {
        renderer.render(scene);
    }

    return 0;
}