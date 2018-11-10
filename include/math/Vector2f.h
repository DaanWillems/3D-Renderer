//
// Created by Daan on 05/11/2018.
//

#include <ui/Renderable.h>
#include <ui/sdl/Frame.h>

#ifndef RDALGEBRA2_VECTOR_H
#define RDALGEBRA2_VECTOR_H

namespace math {
class Vector2f: public ui::Renderable {
    public:
        Vector2f();
        Vector2f(float x, float y);

        Vector2f add(Vector2f vector);
        Vector2f substract(Vector2f vector);

        Vector2f operator+(const Vector2f other);
        Vector2f operator-(const Vector2f other);
        Vector2f operator*(const float scale);

        Vector2f operator+=(const Vector2f other);
        Vector2f operator-=(const Vector2f other);
        Vector2f operator*=(const float scale);

        void draw(ui::sdl::Frame& frame) override;

        float x;
        float y;
    };
}

#endif //RDALGEBRA2_VECTOR_H
