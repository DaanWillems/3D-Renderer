//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/frame.h>

#ifndef RDALGEBRA2_RENDERABLE_H
#define RDALGEBRA2_RENDERABLE_H
namespace ui {
    class renderable {
    public:
        virtual void draw(sdl::frame& frame)=0;
    };
}

#endif //RDALGEBRA2_RENDERABLE_H
