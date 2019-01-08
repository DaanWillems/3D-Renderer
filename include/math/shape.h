//
// Created by Daan on 23/11/2018.
//

#ifndef RDALGEBRA2_SHAPE_H
#define RDALGEBRA2_SHAPE_H

#include <vector>
#include "vector.h"
#include "mat4.h"

namespace math {
    class shape: public ui::renderable  {
    public:
        std::vector<vector> points;
        void draw(ui::sdl::frame& frame) override;
        void multiply(mat4 &other);
    };
}

#endif //RDALGEBRA2_SHAPE_H
