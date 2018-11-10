//
// Created by Daan on 05/11/2018.
//

#include <math/Vector2f.h>

#include "../../include/math/Vector2f.h"

math::Vector2f::Vector2f() {
    x = 0;
    y = 0;
}

math::Vector2f::Vector2f(float x, float y): x{x}, y{y} { }

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
    return vector;
}

math::Vector2f math::Vector2f::operator*(const float scale) {
    Vector2f vector;
    vector.x = this->x * scale;
    vector.y = this->y * scale;
    return vector;
}

math::Vector2f math::Vector2f::operator*=(const float scale) {
    this->x = this->x * scale;
    this->y = this->y * scale;
    return *this;
}

math::Vector2f math::Vector2f::operator+=(const math::Vector2f other) {
    this->x = this->x + other.x;
    this->y = this->y + other.y;
    return *this;
}

math::Vector2f math::Vector2f::operator-=(const math::Vector2f other) {
    this->x = this->x - other.x;
    this->y = this->y - other.y;
    return *this;}

void math::Vector2f::draw(ui::sdl::Frame& frame) {
    frame.draw_rectangle(static_cast<int>(x - 3), static_cast<int>(y + 3), 6, 6);
}
