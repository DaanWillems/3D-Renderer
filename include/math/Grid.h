//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_GRID_H
#define RDALGEBRA2_GRID_H

#include <ui/Renderable.h>
#include <ui/sdl/Frame.h>
#include <vector>
#include "Vector.h"

namespace math {
class Grid: public ui::Renderable {
    public:
        void draw(ui::sdl::Frame& frame) override;
    };
}

#endif //RDALGEBRA2_GRID_H
