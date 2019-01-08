//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_GRID_H
#define RDALGEBRA2_GRID_H

#include <ui/renderable.h>
#include <ui/sdl/frame.h>
#include <vector>
#include "vec4.h"

namespace math {
class grid: public ui::renderable {
    public:
        void draw(ui::sdl::frame& frame) override;
    };
}

#endif //RDALGEBRA2_GRID_H
