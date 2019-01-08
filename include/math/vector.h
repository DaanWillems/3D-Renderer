//
// Created by Daan on 05/11/2018.
//

#ifndef RDALGEBRA2_VECTOR_H
#define RDALGEBRA2_VECTOR_H

namespace math {
    class mat4;
}

#include <ui/renderable.h>
#include <ui/sdl/frame.h>
#include "math/mat4.h"
#include <vector>
#include <string>

namespace math {
class vector: public ui::renderable {
    public:
        vector();
        vector(float x, float y);
        vector(float x, float y, float z);

        float x();
        float y();
        float z();

        vector add(vector vector);
        vector substract(vector vector);
        void invert();

        vector operator+(const vector other);
        vector operator-(const vector other);
        vector operator*(const float scale);

        vector operator+=(const vector other);
        vector operator-=(const vector other);
        vector operator*=(const float scale);

        vector multiply(mat4& matrix);
        std::string toString();
        void draw(ui::sdl::frame& frame) override;

        std::vector<float> data;
    };
}

#endif //RDALGEBRA2_VECTOR_H
