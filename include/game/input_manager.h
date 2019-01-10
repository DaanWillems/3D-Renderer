#pragma once

#pragma once
#include <SDL2/SDL.h>
#include <map>
#include <vector>
#include <game/key.h>

namespace game {

  class input_manager {
  public:
    input_manager();


    /// <summary>
    /// Check if a certain key is pressed.
    /// </summary>
    /// <param name="key">A key value of the Key enum type.</param>
    bool is_key_pressed(key key) const;

    bool is_mouse_button_pressed(key key);

    std::vector<int> get_mouse_position() const;

  private:
    std::map<key, SDL_Scancode> keyMap;
    std::map<key, int> buttonMap;
  };

}