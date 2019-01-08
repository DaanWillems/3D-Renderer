//
// Created by Daan on 23/11/2018.
//

#ifndef RDALGEBRA2_SHAPE_H
#define RDALGEBRA2_SHAPE_H

#include <vector>
#include "vec4.h"
#include "mat4.h"

namespace math {
    class shape: public ui::renderable  {
    public:
        std::vector<vec4> points;
        void draw(ui::sdl::frame& frame) override;
        void multiply(mat4 &other);
        std::string toString() const;
    };
}

#endif //RDALGEBRA2_SHAPE_H
