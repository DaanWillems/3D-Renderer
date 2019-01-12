#ifdef main
#undef main
#endif /* main */

#include <iostream>
#include <list>
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
#include <chrono>
#include <ctime>

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


  math::mat4 r2{1.f};

  math::vec4 acc{0.f, 0.f, 1.f};

  float yaw_ = 90.f;

  r2.rotate_axis(yaw_, {0.f, 1.f, 0.f});

  acc = acc.multiply(r2);

  std::cout << acc.toString();

  grid grid{};

  game::spaceship spaceship{};

  scene.renderables.push_back(&spaceship);

  float near_plane{0.1f};
  float far_plane{500.f};
  float alpha{1.5f};

  game::input_manager input;

  math::vec4 eye{0, 60, 60};
  math::vec4 lookat{0, 0, 0};
  math::mat4 projection{1};

  float scale = 1 / (tan((alpha / 2) * (static_cast<float>( M_PI ) / 180)));

  projection.data[0][0] = scale;
  projection.data[1][1] = scale;
  projection.data[2][2] = -far_plane / (far_plane - near_plane);
  projection.data[3][2] = -far_plane * near_plane / (far_plane - near_plane);

  projection.data[3][3] = 0.f;
  projection.data[2][3] = -1.f;

  renderer.projection(projection);
  std::list<game::projectile> projectiles{};
  bool can_shoot{true};

  auto start = std::chrono::system_clock::now();
  auto stop = std::chrono::system_clock::now();

  spaceship.scale({150.f, 150.f, 150.f});

  while (!window.shouldClose()) {

    auto delta_time_clock = stop-start;
    float delta_time = delta_time_clock.count()/10000000.f;
    start = std::chrono::system_clock::now();
    /* Volgens de opdracht is het volgens mij niet nodig om ook de lookat te wijzigen,
     * maar omdat het erop lijkt dat het perspectief een beetje raar doet als ik het wel doe,
     * laat ik het erin. (wow wat een lange zin)
     */

    spaceship.update(delta_time);
    std::cout << std::to_string(delta_time) + "\n";
    spaceship.acceleration(vec4{0.f, 0.f, 0.f});

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
    auto &loc{spaceship.location()};
    auto &rot{spaceship.rotation()};
    if (input.is_key_pressed(game::key::A)) {
      spaceship.yaw(spaceship.yaw() + 1.2f*delta_time);
    }
    if (input.is_key_pressed(game::key::D)) {
      spaceship.yaw(spaceship.yaw() - (1.2f*delta_time));
    }
    if (input.is_key_pressed(game::key::W)) {
      //loc.data[2] += 0.1f;
      spaceship.acceleration(vec4{0.f, 0.f, 0.005f*-delta_time});
    }
    if (input.is_key_pressed(game::key::S)) {
      //spaceship.acceleration(spaceship.acceleration() + vec4{0.f, 0.f, -0.001f / 100});
    }
    if (input.is_key_pressed(game::key::Q)) {
      spaceship.roll(spaceship.roll()-1.2f*delta_time);
    }
    if (input.is_key_pressed(game::key::E)) {
      spaceship.roll(spaceship.roll()+1.2f*delta_time);
    }
    if (input.is_key_pressed(game::key::Z)) {
      spaceship.pitch(spaceship.pitch()-1.2f*delta_time);
    }
    if (input.is_key_pressed(game::key::X)) {
      spaceship.pitch(spaceship.pitch()+1.2f*delta_time);
    }
    if (input.is_key_pressed(game::key::SPACE)) {
      if (can_shoot) {
        can_shoot = false;
        projectiles.push_back(spaceship.shoot());
        scene.renderables.push_back(&projectiles.back());
      }
    } else {
      can_shoot = true;
    }

    for (auto &projectile : projectiles) {
      // TODO: Hier moet iets anders voor genomen worden, maar dit is tijdelijk.
      projectile.location() += normalize(projectile.location()) * (0.1f*delta_time);
     // std::cout << projectile.location().toString();
    }
    auto camera = math::look_at(eye, lookat, {0, 1, 0});


    renderer.view(camera);
    renderer.render(scene);
    spaceship.rotation({i, 0, 0});
    i += 0.1f;
    stop = std::chrono::system_clock::now();
  }

  return 0;
}
