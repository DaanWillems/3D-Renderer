#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/window.h>
#include <ui/renderer.h>
#include <math/vector.h>
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
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long) handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    ui::sdl::window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    renderer renderer{window};
    scene scene{};

    math::mat4 matrix{0.f};
    auto vectorTranslate = math::vector{25.f, 25.f};
    auto vectorScale = math::vector{2.f, 2.f};

   // mat4.translate(vectorTranslate);
   // matrix.rotate(0.1);
    //mat4.scale(vectorScale);
    std::cout << matrix.toString() << std::endl;

    math::vector vector1{-20, -20, 1};
    math::vector vector2{20, -20, 1};
    math::vector vector3{20, 20, 1};
    math::vector vector4{-20, 20, 1};
    math::vector vector5{-20, -20, 1};

    shape shape;
    shape.points.push_back(vector1);
    shape.points.push_back(vector2);
    shape.points.push_back(vector3);
    shape.points.push_back(vector4);
    shape.points.push_back(vector5);

    //shape.multiply(mat4);

    grid grid{};

    scene.renderables.push_back(dynamic_cast<renderable*>(&shape));
    scene.renderables.push_back(dynamic_cast<renderable*>(&grid));

    while(!window.shouldClose()) {
        renderer.render(scene);
       // mat4.rotate(0.01);
      //  shape.multiply(matrix);
    }

    return 0;
}