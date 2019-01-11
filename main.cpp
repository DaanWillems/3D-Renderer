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
#include <game/spaceship.h>

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

  math::vec4 vector1{-20, -20, 0, 1.f};
  math::vec4 vector2{20, -20, 0, 1.f};
  math::vec4 vector3{20, 20, 0, 1.f};
  math::vec4 vector4{-20, 20, 0, 1.f};
  math::vec4 vector5{-20, -20, 0, 1.f};

  math::vec4 vector6{-20, -20, 20, 1.f};
  math::vec4 vector7{20, -20, 20, 1.f};
  math::vec4 vector8{20, -20, 0, 1.f};

  float i = 0.f;

  //shape2.location(vec4{-70.f, 0.f});
  //shape2.rotation({40.f, 40.f});
  grid grid{};

//  auto obj{ui::mesh_loader().make_mesh(game::paperplane2)};
  game::spaceship spaceship{};

  scene.renderables.push_back(&spaceship);

  float near_plane{0.1f};
  float far_plane{500.f};
  float alpha{1.5f};

  spaceship.location({0, 0, 5});
  game::input_manager input;

  math::vec4 eye{0, 0, 20};
  math::vec4 lookat{0, 0, 0};

  while (!window.shouldClose()) {
    float scale = 1 / (tan((alpha / 2) * (static_cast<float>(M_PI) / 180)));

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
      eye.data[2] += 0.1f;
      lookat.data[2] += 0.1f;
    }
    if (input.is_key_pressed(game::key::DOWN)) {
      eye.data[2] -= 0.1f;
      lookat.data[2] += 0.1f;
    }

    auto& loc{spaceship.location()};
    auto& rot{spaceship.rotation()};
    if (input.is_key_pressed(game::key::A)) {
      loc.data[0] += 0.1f;
    }
    if (input.is_key_pressed(game::key::D)) {
      loc.data[0] -= 0.1f;
    }
    if (input.is_key_pressed(game::key::W)) {
      loc.data[2] += 0.1f;
    }
    if (input.is_key_pressed(game::key::S)) {
      loc.data[2] -= 0.1f;
    }
    if (input.is_key_pressed(game::key::Q)) {
      rot.data[1] += 0.1f;
    }
    if (input.is_key_pressed(game::key::E)) {
      rot.data[1] -= 0.1f;
    }
    if (input.is_key_pressed(game::key::Z)) {
      rot.data[0] += 0.1f;
    }
    if (input.is_key_pressed(game::key::X)) {
      rot.data[0] -= 0.1f;
    }

    auto camera = math::look_at(eye, lookat, {0, 1, 0});

    math::mat4 projection{1};
    projection.data[0][0] = scale;
    projection.data[1][1] = scale;
    projection.data[2][2] = -far_plane / (far_plane - near_plane);
    projection.data[3][2] = -far_plane * near_plane / (far_plane - near_plane);

    projection.data[3][3] = 0.f;
    projection.data[2][3] = -1.f;

    std::cout << spaceship.location().toString();

    renderer.projection(projection);
    renderer.view(camera);
    renderer.render(scene);
//    obj.rotation({i, 0, 0});
//    obj.location({0, 1, -1});
     spaceship.scale({50.f, 50.f, 50.f});

    i += .2f;
  }

  return 0;
}