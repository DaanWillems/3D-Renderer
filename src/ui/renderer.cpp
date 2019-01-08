//
// Created by solaw on 05/11/2018.
//

#include <ui/renderer.h>
#include <ui/sdl/frame.h>

ui::renderer::renderer(sdl::window window) {
    frame = sdl::frame(window.gWindow, 640, 640);
}

void ui::renderer::render(scene& scene) {
    frame.clear();
    for(auto renderable : scene.renderables) {
        renderable->draw(frame);
    }
    frame.swap();
}
