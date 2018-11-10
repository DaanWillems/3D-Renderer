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
        explicit Frame(SDL_Window *window, int width, int height);
        void draw_rectangle(int x, int y, int width, int height);
        void drawLine(int x1, int y1, int x2, int y2);

        void swap();
        void clear();
    private:
        SDL_Renderer* renderer;
        int windowWidth;
        int windowHeight;
    };
}

#endif //RDALGEBRA2_FRAME_H
