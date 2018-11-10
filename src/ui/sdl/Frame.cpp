//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/Frame.h>

#include "ui/sdl/Frame.h"

namespace ui::sdl {
    Frame::Frame(SDL_Window *window, int width, int height): windowWidth{width}, windowHeight{height} {
        renderer = SDL_CreateRenderer( window, -1, 0);
    }

    void Frame::draw_rectangle(int x, int y, int width, int height) {
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

        int rasterX = x+(windowWidth/2);
        int rasterY = (windowHeight/2)-y;

        SDL_Rect r = {rasterX, rasterY, width, height};
        SDL_RenderFillRect(renderer, &r);
    }

    void Frame::drawLine(int x1, int y1, int x2, int y2) {
        int rasterX1 = x1+(windowWidth/2);
        int rasterX2 = x2+(windowWidth/2);
        int rasterY1 = (windowHeight/2)-y1;
        int rasterY2 = (windowHeight/2)-y2;

        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderDrawLine(renderer, rasterX1, rasterY1, rasterX2, rasterY2);
    }

    void Frame::swap() {
        SDL_RenderPresent(renderer);
    }

    void Frame::clear() {
        SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255 );
        SDL_RenderClear( renderer );
    }
}