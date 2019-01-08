#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/window.h>
#include <ui/renderer.h>
#include <math/vec4.h>
#include <math/Grid.h>
#include <math/mat4.h>
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
    FILE *hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE *hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    ui::sdl::window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    renderer renderer{window};
    scene scene{};

    math::mat4 matrix{1.f};
    auto vectorScale = math::vec4{2.f, 2.f, 2.f};
    auto vectorTranslate = math::vec4{80.f, 80.f, 80.f};

    matrix.translate(vectorTranslate);
    matrix.rotate(40, vec4{1, 0, 0});
    matrix.rotate(40, vec4{0, 0, 1});
    //matrix.scale(vectorScale);

    std::cout << "---------\n";
    std::cout << matrix.toString() << std::endl;

    math::vec4 vector1{-20, -20, 0, 1.f};
    math::vec4 vector2{20, -20, 0, 1.f};
    math::vec4 vector3{20, 20, 0, 1.f};
    math::vec4 vector4{-20, 20, 0, 1.f};
    math::vec4 vector5{-20, -20, 0, 1.f};

    math::vec4 vector6{-20, -20, -20, 1.f};
    math::vec4 vector7{20, -20, -20, 1.f};
    math::vec4 vector8{20, -20, 0, 1.f};

    shape shape;
    shape.points.push_back(vector1);
    shape.points.push_back(vector2);
    shape.points.push_back(vector3);
    shape.points.push_back(vector4);
    shape.points.push_back(vector5);
    shape.points.push_back(vector6);
    shape.points.push_back(vector7);
    shape.points.push_back(vector8);

    shape.multiply(matrix);


    grid grid{};

    scene.renderables.push_back(dynamic_cast<renderable *>(&shape));
    scene.renderables.push_back(dynamic_cast<renderable *>(&grid));

    while (!window.shouldClose()) {
        renderer.render(scene);
    }

    return 0;
}