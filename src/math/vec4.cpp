//
// Created by Daan on 05/11/2018.
//

#include <math/vec4.h>
#include <iostream>
#include <cmath>

namespace math {

    vec4::vec4() {
        data.push_back(0.f);
        data.push_back(0.f);
        data.push_back(0.f);
        data.push_back(0.f);
    }

    vec4::vec4(float x, float y) {
        data.push_back(x);
        data.push_back(y);
        data.push_back(0.f);
        data.push_back(0.f);
    }

    vec4::vec4(float x, float y, float z) {
        data.push_back(x);
        data.push_back(y);
        data.push_back(z);
        data.push_back(0.f);
    }

    vec4::vec4(float x, float y, float z, float w) {
        data.push_back(x);
        data.push_back(y);
        data.push_back(z);
        data.push_back(w);
    }

    float vec4::x() {
        return data[0];
    }

    float vec4::y() {
        return data[1];
    }

    float vec4::z() {
        return data[2];
    }

    float vec4::w() {
        return data[3];
    }

    void vec4::x(float val) {
        data[0] = val;
    }

    void vec4::y(float val) {
        data[1] = val;
    }

    void vec4::z(float val) {
        data[2] = val;
    }

    void vec4::w(float val) {
        data[3] = val;
    }

    vec4 vec4::add(math::vec4 vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] += vector.data[i];
        }
        return *this;
    }

    vec4 vec4::substract(math::vec4 vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] -= vector.data[i];
        }
        return *this;
    }

    void vec4::invert() {
        for (float &i : data) {
            i = -i;
        }
    }

    vec4 vec4::operator+(const math::vec4 other) {
        vec4 vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] + other.data[i];
        }
        return vector;
    }

    vec4 vec4::operator-(const math::vec4 other) {
        vec4 vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] - other.data[i];
        }
        return vector;
    }

    vec4 vec4::operator-(const float other) {
        vec4 vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] - other;
        }
        return vector;
    }

    vec4 vec4::operator*(const float scale) {
        vec4 vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] * scale;
        }
        return vector;
    }

    vec4 vec4::operator*=(const float scale) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] * scale;
        }
        return *this;
    }

    vec4 vec4::operator+=(const math::vec4 other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] + other.data[i];
        }
        return *this;
    }

    vec4 vec4::operator-=(const math::vec4 other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] - other.data[i];
        }
        return *this;
    }

    void vec4::draw(ui::sdl::frame &frame, math::mat4 projection, math::mat4 view_) {
        frame.draw_rectangle(static_cast<int>(x() - 3), static_cast<int>(y() + 3), 6, 6);
    }

    vec4 vec4::multiply(mat4 &matrix) const {
        vec4 new_vector{0.f, 0.f, 0.f, 1.f};
        for (int i = 0; i < matrix.rows; i++) {
            float value = 0;
            for (int j = 0; j < data.size(); j++) {
                value += data[j] * matrix.data[i][j];
            }
            new_vector.data[i] = value;
        }
//        std::cout << new_vector.toString();
        return new_vector;
    }

    std::string vec4::toString() {
        std::string result{};
        result.append(std::to_string(x()));
        result.append(" | ");
        result.append(std::to_string(y()));
        result.append(" | ");
        result.append(std::to_string(z()));
        result.append(" | ");
        result.append(std::to_string(w()));
        result.append("\n");
        return result;
    }

    float vec4::dot(const vec4 &other) const {
        float cum{0};

        for (unsigned i = 0; i < data.size(); ++i) {
            cum += data.at(i) * other.data.at(i);
        }

        return cum;
    }

    vec4 vec4::cross(const vec4 &other) const {
        vec4 result{0, 0, 0, 0};

        result.x((data[1] * other.data[2]) - (data[2] * other.data[1]));
        result.y((data[2] * other.data[0]) - (data[0] * other.data[2]));
        result.z((data[0] * other.data[1]) - (data[1] * other.data[0]));

        return result;
    }

    float vec4::length() const {
        return sqrt((data[0] * data[0]) + (data[1] * data[1]) + (data[2] * data[2]));
    }

    vec4 vec4::normalize() {
        auto length = this->length();
        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] / length;
        }
        return *this;
    }

    vec4 vec4::truncate(float max) {
        auto length = this->length();
        if (length > max) {
            this->normalize();
            this->data = (*this * max).data;
        }
        return *this;
    }

    bool vec4::operator==(const vec4 other) {
        for (int i = 0; i < data.size(); i++) {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    bool vec4::operator!=(const vec4 other) {
        return !(*this == other);
    }


    vec4 normalize(vec4 v) {
        auto length = v.length();
        for (int i = 0; i < v.data.size(); i++) {
            v.data[i] = v.data[i] / length;
        }
        return v;
    }

    vec4 invert(vec4 v) {
        for (int i = 0; i < v.data.size(); i++) {
            v.data[i] = -v.data[i];
        }
        return v;
    }

    float dist(vec4 v1, vec4 v2) {
        auto v3 = v2 - v1;
        auto length = v3.length();
        return length;
    }

    vec4 truncate(vec4 v, float max) {
        auto length = v.length();
        if (length > max) {
            v.normalize();
            v.data = (v * max).data;
        }
        return v;
    }
}