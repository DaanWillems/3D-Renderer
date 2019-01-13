//
// Created by solaw on 12/01/2019.
//

#include <game/projectile.h>
#include <iostream>

namespace game {
    void game::projectile::update(float delta_time) {
        location(location()+((direction_ * 40)*delta_time));
        time_alive_ += delta_time;
    }

    void projectile::direction(math::vec4 direction) {
        direction_ = direction;
    }

    math::vec4 projectile::direction() {
        return direction_;
    }

    bool projectile::expired() {
      return time_alive_ > 30;
    }

    math::vec4 projectile::collision_location() {
      return location();
    }

    int projectile::id() {
      return id_;
    }
}