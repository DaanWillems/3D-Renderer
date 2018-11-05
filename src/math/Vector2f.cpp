//
// Created by Daan on 05/11/2018.
//

#include <math/Vector2f.h>

#include "../../include/math/Vector2f.h"

math::Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

math::Vector2f::Vector2f(int x, int y): x{x}, y{y} {

}

math::Vector2f math::Vector2f::add(math::Vector2f vector) {
    x += vector.x;
    y += vector.y;
    return *this;
}

math::Vector2f math::Vector2f::substract(math::Vector2f vector) {
    x += vector.x;
    y += vector.y;
    return *this;
}

math::Vector2f math::Vector2f::operator+(const math::Vector2f other) {
    Vector2f vector;
    vector.x = this->x + other.x;
    vector.y = this->y + other.y;
    return vector;
}

math::Vector2f math::Vector2f::operator-(const math::Vector2f other) {
    Vector2f vector;
    vector.x = this->x - other.x;
    vector.y = this->y - other.y;
    return vector;}

void math::Vector2f::draw(ui::sdl::Frame& frame) {
    frame.draw_rectangle(10, 10, 10, 10);
}
