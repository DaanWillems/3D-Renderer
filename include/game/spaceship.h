#pragma once

#include <game/game_object.h>
#include <game/cube.h>
#include <game/projectile.h>

namespace game{
class spaceship : public game_object {
public:
  spaceship() : game_object(game::paperplane2) {
    scale({150.f, 150.f, 150.f});
  }

  projectile shoot();
};
}