//
// Created by vincent on 11/15/18.
//

#ifndef RDALGEBRA2_MATRIX_H
#define RDALGEBRA2_MATRIX_H

namespace math {
    class vec4;
}

#include <vector>
#include <stdexcept>
#include <string>
#include "math/vec4.h"

namespace math {
    class mat4 {
    public:
        mat4(float initValue);

        void translate(math::vec4 &other);

        void scale(math::vec4 other);

        void rotate(float angle, vec4 axis);

        void rotate_axis(float angle, vec4 point);

        void invert();

        mat4 operator+(const mat4 &other) const;

        mat4 operator-(const mat4 &other) const;

        mat4 operator*(const mat4 &other) const;

        mat4 operator*=(const mat4 &other);

        bool operator==(const mat4 &other);

        bool operator!=(const mat4 &other);

        std::string toString() const;

        std::vector<std::vector<float>> data;
        int rows;
        int columns;
    };

    mat4 look_at(vec4 eye, vec4 center, vec4 up);
}
#endif //RDALGEBRA2_MATRIX_H
