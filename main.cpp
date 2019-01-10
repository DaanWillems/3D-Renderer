#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/window.h>
#include <ui/renderer.h>
#include <math/vec4.h>
#include <math/grid.h>
#include <math/mat4.h>
#include <math/mesh.h>

#include <stdio.h>
#include <fcntl.h>

#ifdef _WIN32

#include <io.h>
#include <windows.h>
#include <cmath>

#endif
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

using namespace ui;
using namespace math;
using namespace ui::sdl;

int main(int argc, char *argv[]) {
#ifdef _WIN32

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
#endif
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
//    matrix.scale(vectorScale);

    std::cout << "---------\n";
    std::cout << matrix.toString() << std::endl;


    math::vec4 v1{0, 1.f};
    math::vec4 v2{0, 1.f};
    std::cout << "Dot: " << v1.dot(v2) << "\n";

    math::vec4 vector1{-20, -20, 0, 1.f};
    math::vec4 vector2{20, -20, 0, 1.f};
    math::vec4 vector3{20, 20, 0, 1.f};
    math::vec4 vector4{-20, 20, 0, 1.f};
    math::vec4 vector5{-20, -20, 0, 1.f};

    math::vec4 vector6{-20, -20, 20, 1.f};
    math::vec4 vector7{20, -20, 20, 1.f};
    math::vec4 vector8{20, -20, 0, 1.f};

    mesh shape;
    shape.points.push_back(vector1);
    shape.points.push_back(vector2);
    shape.points.push_back(vector3);
    shape.points.push_back(vector4);
    shape.points.push_back(vector5);
    shape.points.push_back(vector6);
    shape.points.push_back(vector7);
    shape.points.push_back(vector8);

//    mesh.model_matrix(matrix);
    //   shape.model_matrix(std::move(matrix));
    //mesh.multiply(matrix);


    float i = 0.f;

    mesh shape2;
    shape2.points.push_back(vector1);
    shape2.points.push_back(vector2);
    shape2.points.push_back(vector3);
    shape2.points.push_back(vector4);
    shape2.points.push_back(vector5);
    shape2.points.push_back(vector6);
    shape2.points.push_back(vector7);
    shape2.points.push_back(vector8);

    //shape2.location(vec4{-70.f, 0.f});
    //shape2.rotation({40.f, 40.f});
    grid grid{};



    scene.renderables.push_back(&shape);
    scene.renderables.push_back(&shape2);
   // scene.renderables.push_back(&grid);

    float near_plane{0.1f};
    float far_plane{500.f};
    float alpha{4.5f};

    shape.location({0, 0, 50});
    shape2.location({0, 0, 5});
    float a{0};

    while (!window.shouldClose()) {
        float scale = 1 / (tan((alpha / 2) * (M_PI / 180)));

      //  alpha += 0.1;

        a += 0.005;

        auto camera = math::look_at({0, 0, 0}, {0, 0, 50}, {0, 1, 0});

        math::mat4 projection{1};
        projection.data[0][0] = scale;
        projection.data[1][1] = scale;
        projection.data[2][2] = -far_plane / (far_plane - near_plane);
        projection.data[3][2] = -far_plane * near_plane / (far_plane - near_plane);

        projection.data[3][3] = 0.f;
        projection.data[2][3] = -1.f;

        std::cout << projection.toString()+"\n";
        renderer.projection(projection);
        renderer.view(camera);
        renderer.render(scene);
        shape.rotation({i, 0, 0});
        //shape.location({i, 0, 50});
       // shape.rotation({i, 0, 0});
      //  shape.scale({1.1f, 1.1f, 1.1f});
        i += .6f;
    }

    return 0;
}