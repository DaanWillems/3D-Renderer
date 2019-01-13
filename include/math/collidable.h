//
// Created by solaw on 13/01/2019.
//

#ifndef RDALGEBRA2_COLLIDABLE_H
#define RDALGEBRA2_COLLIDABLE_H

#include "vec4.h"

namespace math {
    class collidable {
    public:
        bool check_collision(collidable& target) {
          auto dist = math::dist(this->collision_location(), target.collision_location());
          auto sum_radius = this->collision_radius() + target.collision_radius();
          return dist < sum_radius;
        }

        virtual math::vec4 collision_location()=0;

        virtual float collision_radius() {
          return collision_radius_;
        }
    private:
        float collision_radius_{10.f};
    };
}

#endif //RDALGEBRA2_COLLIDABLE_H
