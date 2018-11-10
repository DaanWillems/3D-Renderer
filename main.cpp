#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/Window.h>
#include <ui/Renderer.h>
#include <math/Vector2f.h>
#include <math/Grid.h>

#ifdef main
#undef main
#endif /* main */

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;

using namespace ui;
using namespace math;
using namespace ui::sdl;

int main(int argc, char *argv[]) {

    ui::sdl::Window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    Renderer renderer{window};
    Scene scene{};

    Vector2f vector1{40, 40};
    vector1 *= 2;

    Vector2f vector2{40, -40};
    vector2 += Vector2f{40, 00};

    Vector2f vector3{-40, 40};
    vector3 -= Vector2f{40, 00};

    Grid grid{};

    scene.renderables.push_back(dynamic_cast<Renderable*>(&vector1));
    scene.renderables.push_back(dynamic_cast<Renderable*>(&vector2));
    scene.renderables.push_back(dynamic_cast<Renderable*>(&vector3));
    scene.renderables.push_back(dynamic_cast<Renderable*>(&grid));

    while(!window.shouldClose()) {
        renderer.render(scene);
    }

    return 0;
}