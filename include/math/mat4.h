//
// Created by vincent on 11/15/18.
//

#ifndef RDALGEBRA2_MATRIX_H
#define RDALGEBRA2_MATRIX_H

namespace math {
    class vector;
}

#include <vector>
#include <stdexcept>
#include <string>
#include "math/Vector.h"

namespace math {
    class mat4 {
    public:
        mat4(float initValue);

        void translate(math::vector& other);
        void scale(math::vector other);
        void rotate(float angle);
        void invert();

        mat4 operator+(const mat4 &other) const;
        mat4 operator-(const mat4 &other) const;
        mat4 operator*(const mat4 &other) const;

        mat4 operator*=(const mat4 &other);

        std::string toString() const;
        std::vector<std::vector<float>> data;
        int rows;
        int columns;
    };
}
#endif //RDALGEBRA2_MATRIX_H
