#pragma once

#pragma once

#include <game/game_object.h>
#include <game/cube.h>

namespace game{
class projectile : public game_object {
public:
  projectile() : game_object(game::cubic_cube) {
    scale({.05f, .05f, .05f});
  }
};
}