//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_RENDERER_H
#define RDALGEBRA2_RENDERER_H

#include <ui/scene.h>
#include <ui/sdl/frame.h>

namespace ui {
    class renderer {
    public:
        renderer(sdl::window window);
        void render(scene& scene);
    private:
        sdl::frame frame;
    };
}

#endif //RDALGEBRA2_RENDERER_H
