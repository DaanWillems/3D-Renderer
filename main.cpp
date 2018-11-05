#include <iostream>
#include <SDL2/SDL.h>
#include <stdio.h>
#include <ui/sdl/Window.h>
#include <ui/Renderer.h>
#include <math/Vector2f.h>

#ifdef main
#undef main
#endif /* main */

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

using namespace ui;
using namespace math;
using namespace ui::sdl;

int main(int argc, char *argv[]) {

    ui::sdl::Window window{};
    window.init("Test", SCREEN_WIDTH, SCREEN_HEIGHT, 10, 10);

    Renderer renderer{window};

    Scene scene{};

    Vector2f vector2f{};
    scene.renderables.push_back(dynamic_cast<Renderable*>(&vector2f));

    while(!window.shouldClose()) {
        renderer.render(scene);
    }

    return 0;
}