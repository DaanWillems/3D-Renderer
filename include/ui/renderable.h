//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/frame.h>
#include <memory>

#ifndef RDALGEBRA2_RENDERABLE_H
#define RDALGEBRA2_RENDERABLE_H

namespace math {
    class mat4;
}

namespace ui {
    class renderable {
    public:
        virtual void draw(sdl::frame& frame)=0;
        virtual math::mat4& model_matrix() {

        }

        virtual void model_matrix(math::mat4&&) {

        }
    };
}

#endif //RDALGEBRA2_RENDERABLE_H
