//
// Created by vincent on 11/15/18.
//

#ifndef RDALGEBRA2_MATRIX_H
#define RDALGEBRA2_MATRIX_H

namespace math {
    class Vector;
}

#include <vector>
#include <stdexcept>
#include <string>
#include "math/Vector.h"

namespace math {
    class Matrix {
    public:
        Matrix(int rows, int columns, float initValue);

        void translate(math::Vector& other);
        void scale(math::Vector other);
        void rotate(float angle);
        void invert();

        Matrix operator+(const Matrix &other) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator*(const Matrix &other) const;

        Matrix operator*=(const Matrix &other);

        std::string toString() const;
        std::vector<std::vector<float>> data;
        int rows;
        int columns;
    };
}
#endif //RDALGEBRA2_MATRIX_H
