//
// Created by solaw on 05/11/2018.
//

#include <ui/sdl/window.h>
#include <SDL2/SDL.h>
#include <iostream>


using namespace std;

void ui::sdl::window::init(const char *title, const int width, const int height, const int x, const int y) {
    this->width = width;
    this->height = height;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << endl;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("window could not be created! SDL Error: %s\n", SDL_GetError());
        }
    }
}

bool ui::sdl::window::shouldClose()
{
    SDL_Event e;
    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            this->close();
            return true;
        }
    }
    return false;
}

void ui::sdl::window::close() {
    if (gWindow == nullptr) {
        std::cout << "window was never initialized" << std::endl;
        SDL_DestroyWindow(gWindow);
    }
    SDL_Quit();
}