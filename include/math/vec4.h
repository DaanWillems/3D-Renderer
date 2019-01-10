#pragma once

namespace math {
    class mat4;
}

#include <ui/renderable.h>
#include <ui/sdl/frame.h>
#include "math/mat4.h"
#include <vector>
#include <string>

namespace math {
class vec4: public ui::renderable {
    public:
        vec4();
        vec4(float x, float y);
        vec4(float x, float y, float z);
        vec4(float x, float y, float z, float w);

        float x();
        float y();
        float z();
        float w();

        void x(float val);
        void y(float val);
        void z(float val);
        void w(float val);

        vec4 add(vec4 vector);
        vec4 substract(vec4 vector);
        void invert();

        vec4 operator+(const vec4 other);
        vec4 operator-(const vec4 other);
        vec4 operator*(const float scale);

        vec4 operator+=(const vec4 other);
        vec4 operator-=(const vec4 other);
        vec4 operator*=(const float scale);

        vec4 multiply(mat4& matrix);
        float dot(const vec4 &other) const;
        vec4 cross(const vec4 &other) const;
        float length() const;
        vec4 normalize();

        std::string toString();
        void draw(ui::sdl::frame& frame, math::mat4 projection, math::mat4 view_) override;

        std::vector<float> data;
    };

    vec4 normalize(vec4 v);
}

