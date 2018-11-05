//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/Frame.h>

#include "ui/sdl/Frame.h"

namespace ui::sdl {
    Frame::Frame(SDL_Window *window) {
        renderer = SDL_CreateRenderer( window, -1, 0);
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        SDL_RenderClear( renderer );

        SDL_Rect rectToDraw = {100,100,100,100};
        SDL_RenderFillRect(renderer, &rectToDraw);
        SDL_RenderPresent(renderer); // copy to screen
    }

    void Frame::draw_rectangle(float width, float height, float x, float y) {
        SDL_RenderClear( renderer ); //TODO: Move this to window

        SDL_Rect r = {10,10,10,10};

        SDL_RenderFillRect(renderer, &r);

        SDL_RenderPresent(renderer); //TODO: Move this to window

    }
}