#pragma once

namespace math {
    class mat4;
}

#include <ui/renderable.h>
//#include "math/mat4.h"
#include <vector>
#include <string>
#include "ui/sdl/frame.h"

namespace ui {
    namespace sdl {
        class frame;
    }
}

namespace ui {
    namespace sdl {
    }
}

namespace math {
class vec4 {
    public:
        vec4();
        vec4(float x, float y);
        vec4(float x, float y, float z);
        vec4(float x, float y, float z, float w);

        float x() const;
        float y() const;
        float z() const;
        float w() const;

        void x(float val);
        void y(float val);
        void z(float val);
        void w(float val);

        vec4 add(vec4 vector);
        vec4 substract(vec4 vector);
        void invert();

        vec4 operator+(const vec4 other);
        vec4 operator-(const vec4 other);
        vec4 operator-(const float other);
        vec4 operator*(const float scale);

        vec4 operator+=(const vec4 other);
        vec4 operator-=(const vec4 other);
        vec4 operator*=(const float scale);
        bool operator==(const vec4 other);
        bool operator!=(const vec4 other);

        vec4 multiply(const mat4& matrix) const;
        float dot(const vec4 &other) const;
        vec4 cross(const vec4 &other) const;
        float length() const;
        vec4 normalize();
        vec4 truncate(float max);

        std::string toString();

        std::vector<float> data;
    };

    vec4 normalize(vec4 v);
    vec4 invert(vec4 v);
    float dist(vec4 v1, vec4 v2);
    vec4 truncate(vec4 v, float max);
}

