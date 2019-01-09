//
// Created by Daan on 05/11/2018.
//

#include <math/vec4.h>
#include <iostream>

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

    void vec4::draw(ui::sdl::frame &frame) {
        frame.draw_rectangle(static_cast<int>(x() - 3), static_cast<int>(y() + 3), 6, 6);
    }

    vec4 vec4::multiply(mat4 &matrix) {
        vec4 new_vector{0.f, 0.f, 0.f, 1.f};
        for (int i = 0; i < matrix.rows; i++) {
            float value = 0;
            for (int j = 0; j < data.size(); j++) {
                value += data[j] * matrix.data[i][j];
            }
            new_vector.data[i] = value;
        }
        std::cout << new_vector.toString();
        return new_vector;
    }

    std::string vec4::toString() {
        std::string result = "";
        result.append(std::to_string(x()));
        result.append(" | ");
        result.append(std::to_string(y()));
        result.append(" | ");
        result.append(std::to_string(z()));
        result.append(" | ");
        result.append(std::to_string(w()));
        return result;
    }

  float vec4::dot(const vec4 &other) const {
        float cum{0};

        for (unsigned i = 0; i < data.size(); ++i) {
            cum += data.at(i) * other.data.at(i);
        }

        return cum;
  }


}