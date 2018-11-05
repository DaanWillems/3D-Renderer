//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_FRAME_H
#define RDALGEBRA2_FRAME_H

class Window;
#include <ui/sdl/Window.h>

namespace ui::sdl {
    class Frame {
    public:
        Frame()= default;
        explicit Frame(SDL_Window *window);
        void draw_rectangle(float width, float height, float x, float y);

    private:
        SDL_Renderer* renderer;
    };
}

#endif //RDALGEBRA2_FRAME_H
