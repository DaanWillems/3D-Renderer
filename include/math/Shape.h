//
// Created by Daan on 23/11/2018.
//

#ifndef RDALGEBRA2_SHAPE_H
#define RDALGEBRA2_SHAPE_H

#include <vector>
#include "Vector.h"
#include "Matrix.h"

namespace math {
    class Shape: public ui::Renderable  {
    public:
        std::vector<Vector> points;
        void draw(ui::sdl::Frame& frame) override;
        void multiply(Matrix &other);
    };
}

#endif //RDALGEBRA2_SHAPE_H
