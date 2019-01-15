#include <cmath>

//
// Created by solaw on 12/01/2019.
//

#ifndef RDALGEBRA2_PLANET_H
#define RDALGEBRA2_PLANET_H

#include "game_object.h"
#include "cube.h"
#include <chrono>
#include <ctime>
#include <cmath>
#include <iostream>

namespace game {
    class planet : public game_object, public math::collidable {
    public:
        planet() : game_object(game::cubic_cube) {
          scale({1.f, 1.f, 1.f});
        }

        void update(float);

        math::vec4 collision_location() override {
          return location();
        }

        float collision_radius() override {
          return 10.f * scale().x();
        }

    private:
        float scale_pulse_{0.f};
    };

    void planet::update(float delta_time) {
      auto i = std::sin(scale_pulse_);
      scale_pulse_ += 0.1f * delta_time;
      i += 2;
      scale({i, i, i});
    }
}

#endif //RDALGEBRA2_PLANET_H
