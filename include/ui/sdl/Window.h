//
// Created by solaw on 05/11/2018.
//

#ifndef RDALGEBRA2_WINDOW_H
#define RDALGEBRA2_WINDOW_H

#include <SDL.h>

namespace ui::sdl {
    class Window {
    public:
        void init(const char* title, int width, int height, int x, int y);
        bool shouldClose();
        void close();

        int width;
        int height;

        SDL_Window *gWindow;
    };
}


#endif //RDALGEBRA2_WINDOW_H
