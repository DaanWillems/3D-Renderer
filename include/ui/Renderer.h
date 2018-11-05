//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_RENDERER_H
#define RDALGEBRA2_RENDERER_H

#include <ui/Scene.h>
#include <ui/sdl/Frame.h>

namespace ui {
    class Renderer {
    public:
        Renderer(sdl::Window window);
        void render(Scene& scene);
    private:
        sdl::Frame frame;
    };
}

#endif //RDALGEBRA2_RENDERER_H
