#pragma once

#pragma once

#include <game/game_object.h>
#include <game/cube.h>
#include <math/collidable.h>

namespace game{
class projectile : public game_object, public math::collidable {
public:
  projectile(int id) : game_object(game::cubic_cube), id_{id} {
    scale({.05f, .05f, .05f});
  }

  void update(float);

  bool expired();

  void direction(math::vec4);

  int id();

  math::vec4 collision_location() override;

  math::vec4 direction();

private:
    float time_alive_{0};
    math::vec4 direction_{1.f, 1.f, 0.f};
    int id_;
};
}