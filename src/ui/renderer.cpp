#include <utility>

//
// Created by solaw on 05/11/2018.
//

#include <ui/renderer.h>
#include <ui/sdl/frame.h>

ui::renderer::renderer(sdl::window window) :
    projection_(math::mat4(0)) {
  frame = sdl::frame(window.gWindow, 640, 640);
}

void ui::renderer::render(scene &scene) {
  frame.clear();
  for (auto renderable : scene.renderables) {
    renderable->draw(frame, projection_);
  }
  frame.swap();
}

void ui::renderer::projection(math::mat4 projection) {
  projection_ = std::move(projection);
}

math::mat4 ui::renderer::projection() {
  return projection_;
}
