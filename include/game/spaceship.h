#pragma once

#include <game/game_object.h>
#include <game/cube.h>

namespace game{
class spaceship : public game_object {
public:
  spaceship() : game_object(game::paperplane2) {}
};
}