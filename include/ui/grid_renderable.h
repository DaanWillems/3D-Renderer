//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_GRIDRENDERABLE_H
#define RDALGEBRA2_GRIDRENDERABLE_H
//
// Created by solaw on 05/11/2018.
//
#include "renderable.h"
#include "ui/sdl/frame.h"

namespace ui {
    class grid_renderable: public renderable {
    public:
        void draw(frame frame) override;
    };
}
#endif //RDALGEBRA2_GRIDRENDERABLE_H
