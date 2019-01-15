#pragma once

#include "game_object.h"
#include "cube.h"
#include <chrono>
#include <ctime>
#include <cmath>
#include <iostream>

namespace game {
  class asteroid : public game_object, public math::collidable {
  public:
    asteroid() : game_object(game::sphere) {
      scale({15.f, 15.f, 15.f});
    }

    void update(float);

    math::vec4 collision_location() override {
      return location();
    }

    float collision_radius() override {
      return 0.25f * scale().x();
    }

  private:
    float scale_pulse_{0.f};
  };

  void asteroid::update(float delta_time) {
    auto i = std::sin(scale_pulse_);
    scale_pulse_ += 0.1f * delta_time;
    i += 2;
    i *= 15.f;
    scale({i, i, i});
  }
}

