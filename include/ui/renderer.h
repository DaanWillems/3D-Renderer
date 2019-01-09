//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_RENDERER_H
#define RDALGEBRA2_RENDERER_H

#include <ui/scene.h>
#include <ui/sdl/frame.h>
#include <math/mat4.h>

namespace ui {
    class renderer {
    public:
        renderer(sdl::window window);

        void render(scene &scene);

        void projection(math::mat4 projection_);

        void view(math::mat4 view_);

        math::mat4 projection();

        math::mat4 view();

    private:
        sdl::frame frame;
        math::mat4 projection_;
        math::mat4 view_;
    };
}

#endif //RDALGEBRA2_RENDERER_H
