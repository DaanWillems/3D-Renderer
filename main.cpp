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
#include <game/input_manager.h>
#include <ui/mesh_loader.h>
#include <game/cube.h>

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

    float i = 0.f;

    grid grid{};

    auto obj{ui::mesh_loader().make_mesh(game::cubic_cube)};
    obj.location({0, 0, 20});

    scene.renderables.push_back(&obj);

    float near_plane{0.1f};
    float far_plane{500.f};
    float alpha{1.5f};

    game::input_manager input;

    math::vec4 eye{0, 0, 40};
    math::vec4 lookat{0, 0, 0};


    while (!window.shouldClose()) {
        float scale = 1 / (tan((alpha / 2) * (M_PI / 180)));

        /* Volgens de opdracht is het volgens mij niet nodig om ook de lookat te wijzigen,
         * maar omdat het erop lijkt dat het perspectief een beetje raar doet als ik het wel doe,
         * laat ik het erin. (wow wat een lange zin)
         */

        if (input.is_key_pressed(game::key::PAGEUP)) {
            eye.data[1] += 0.1f;
            lookat.data[1] += 0.1f;
        }
        if (input.is_key_pressed(game::key::PAGEDOWN)) {
            eye.data[1] -= 0.1f;
            lookat.data[1] -= 0.1f;
        }
        if (input.is_key_pressed(game::key::LEFT)) {
            eye.data[0] += 0.1f;
            lookat.data[0] += 0.1f;
        }
        if (input.is_key_pressed(game::key::RIGHT)) {
            eye.data[0] -= 0.1f;
            lookat.data[0] -= 0.1f;
        }
        if (input.is_key_pressed(game::key::UP)) {
            eye.data[2] += 0.1;
            lookat.data[2] += 0.1;
        }
        if (input.is_key_pressed(game::key::DOWN)) {
            eye.data[2] -= 0.1;
            lookat.data[2] -= 0.1f;
        }

        auto camera = math::look_at(eye, lookat, {0, 1, 0});

        math::mat4 projection{1};
        projection.data[0][0] = scale;
        projection.data[1][1] = scale;
        projection.data[2][2] = -far_plane / (far_plane - near_plane);
        projection.data[3][2] = -far_plane * near_plane / (far_plane - near_plane);

        projection.data[3][3] = 0.f;
        projection.data[2][3] = -1.f;

        renderer.projection(projection);
        renderer.view(camera);
        renderer.render(scene);
        obj.rotation({i, 0, 0});
        //obj.location({0, 1, -1});
        i += 0.1f;
    }

    return 0;
}










































































































































































































































