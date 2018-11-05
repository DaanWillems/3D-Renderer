//
// Created by solaw on 05/11/2018.
//

#include <ui/Renderer.h>

#include "../../include/ui/Renderer.h"
#include "../../include/ui/Scene.h"
#include <ui/sdl/Frame.h>

ui::Renderer::Renderer(sdl::Window window) {
    frame = sdl::Frame(window.gWindow);
}

void ui::Renderer::render(Scene& scene) {
    for(auto renderable : scene.renderables) {
        renderable->draw(frame);
    }

}
