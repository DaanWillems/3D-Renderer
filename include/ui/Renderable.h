//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/Frame.h>

#ifndef RDALGEBRA2_RENDERABLE_H
#define RDALGEBRA2_RENDERABLE_H
namespace ui {
    class Renderable {
    public:
        virtual void draw(sdl::Frame& frame)=0;
    };
}

#endif //RDALGEBRA2_RENDERABLE_H
