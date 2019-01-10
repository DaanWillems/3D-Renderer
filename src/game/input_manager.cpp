#include <game/input_manager.h>
#include <SDL2/SDL.h>
#include <game/key.h>

namespace game {
  input_manager::input_manager() {
    keyMap[key::W] = SDL_SCANCODE_W;
    keyMap[key::A] = SDL_SCANCODE_A;
    keyMap[key::S] = SDL_SCANCODE_S;
    keyMap[key::D] = SDL_SCANCODE_D;
    keyMap[key::Q] = SDL_SCANCODE_Q;
    keyMap[key::E] = SDL_SCANCODE_E;
    keyMap[key::H] = SDL_SCANCODE_H;
    keyMap[key::R] = SDL_SCANCODE_R;
    keyMap[key::T] = SDL_SCANCODE_T;
    keyMap[key::J] = SDL_SCANCODE_J;
    keyMap[key::I] = SDL_SCANCODE_I;
    keyMap[key::K] = SDL_SCANCODE_K;
    keyMap[key::L] = SDL_SCANCODE_L;
    keyMap[key::F3] = SDL_SCANCODE_F3;
    keyMap[key::NUM1] = SDL_SCANCODE_1;
    keyMap[key::NUM2] = SDL_SCANCODE_2;
    keyMap[key::NUM3] = SDL_SCANCODE_3;
    keyMap[key::TAB] = SDL_SCANCODE_TAB;
    keyMap[key::ESCAPE] = SDL_SCANCODE_ESCAPE;
    keyMap[key::MIN] = SDL_SCANCODE_KP_MINUS;
    keyMap[key::PLUS] = SDL_SCANCODE_KP_PLUS;
    keyMap[key::END] = SDL_SCANCODE_END;
    keyMap[key::PAGEUP] = SDL_SCANCODE_PAGEUP;
    keyMap[key::PAGEDOWN] = SDL_SCANCODE_PAGEDOWN;
    keyMap[key::UP] = SDL_SCANCODE_UP;
    keyMap[key::DOWN] = SDL_SCANCODE_DOWN;
    keyMap[key::LEFT] = SDL_SCANCODE_LEFT;
    keyMap[key::RIGHT] = SDL_SCANCODE_RIGHT;
    buttonMap[key::MOUSE_BUTTON_LEFT] = SDL_BUTTON_LEFT;
    buttonMap[key::MOUSE_BUTTON_RIGHT] = SDL_BUTTON_RIGHT;
  }

  bool input_manager::is_key_pressed(game::key key) const {
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

    return currentKeyStates[keyMap.at(key)] != 0;

  }

  bool input_manager::is_mouse_button_pressed(game::key key){
    return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(buttonMap[key])) != 0;
  }

  std::vector<int> input_manager::get_mouse_position() const {
    int x;
    int y;
    std::vector<int> posVector;
    SDL_GetMouseState(&x, &y);
    posVector.push_back(x);
    posVector.push_back(y);

    return posVector;
  }
}