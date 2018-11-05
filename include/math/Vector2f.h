//
// Created by Daan on 05/11/2018.
//

#ifndef RDALGEBRA2_VECTOR_H
#define RDALGEBRA2_VECTOR_H

namespace math {
    class Vector2f {
    public:
        Vector2f();
        Vector2f(int x, int y);

        Vector2f add(Vector2f vector);
        Vector2f substract(Vector2f vector);
        Vector2f multiply(Vector2f vector);

        Vector2f operator*(const Vector2f v);
        Vector2f operator+(const Vector2f v);
        Vector2f operator-(const Vector2f v);


        int x;
        int y;
    };
}

#endif //RDALGEBRA2_VECTOR_H
