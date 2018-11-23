//
// Created by Daan on 05/11/2018.
//

#ifndef RDALGEBRA2_VECTOR_H
#define RDALGEBRA2_VECTOR_H

namespace math {
    class Matrix;
}

#include <ui/Renderable.h>
#include <ui/sdl/Frame.h>
#include "math/Matrix.h"
#include <vector>
#include <string>

namespace math {
class Vector: public ui::Renderable {
    public:
        Vector();
        Vector(float x, float y);
        Vector(float x, float y, float z);

        float x();
        float y();
        float z();

        Vector add(Vector vector);
        Vector substract(Vector vector);
        void invert();

        Vector operator+(const Vector other);
        Vector operator-(const Vector other);
        Vector operator*(const float scale);

        Vector operator+=(const Vector other);
        Vector operator-=(const Vector other);
        Vector operator*=(const float scale);

        Vector multiply(Matrix& matrix);
        std::string toString();
        void draw(ui::sdl::Frame& frame) override;

        std::vector<float> data;
    };
}

#endif //RDALGEBRA2_VECTOR_H
