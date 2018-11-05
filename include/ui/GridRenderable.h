//
// Created by solaw on 05/11/2018.
//
#include <ui/sdl/Frame.h>

#ifndef RDALGEBRA2_GRIDRENDERABLE_H
#define RDALGEBRA2_GRIDRENDERABLE_H
//
// Created by solaw on 05/11/2018.
//
#include "../../include/ui/Renderable.h"
#include "ui/sdl/Frame.h"

namespace ui {
    class GridRenderable: public Renderable {
    public:
        void draw(Frame frame) override;
    };
}
#endif //RDALGEBRA2_GRIDRENDERABLE_H
