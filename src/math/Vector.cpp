//
// Created by Daan on 05/11/2018.
//

#include <math/Vector.h>

namespace math {

    math::Vector::Vector() {
        data.push_back(0.f);
        data.push_back(0.f);
        data.push_back(0.f);
    }

    math::Vector::Vector(float x, float y) {
        data.push_back(x);
        data.push_back(y);
    }

    math::Vector::Vector(float x, float y, float z) {
        data.push_back(x);
        data.push_back(y);
        data.push_back(z);
    }

    float Vector::x() {
        return data[0];
    }

    float Vector::y() {
        return data[1];
    }

    float Vector::z() {
        return data[2];
    }

    Vector Vector::add(math::Vector vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] += vector.data[i];
        }
        return *this;
    }

    Vector Vector::substract(math::Vector vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] -= vector.data[i];
        }
        return *this;
    }

    void Vector::invert() {
        for (float &i : data) {
            i = -i;
        }
    }

    Vector Vector::operator+(const math::Vector other) {
        Vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] + other.data[i];
        }
        return vector;
    }

    Vector Vector::operator-(const math::Vector other) {
        Vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] - other.data[i];
        }
        return vector;
    }

    Vector Vector::operator*(const float scale) {
        Vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] * scale;
        }
        return vector;
    }

    Vector Vector::operator*=(const float scale) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] * scale;
        }
        return *this;
    }

    Vector Vector::operator+=(const math::Vector other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] + other.data[i];
        }
        return *this;
    }

    Vector Vector::operator-=(const math::Vector other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] - other.data[i];
        }
        return *this;
    }

    void Vector::draw(ui::sdl::Frame &frame) {
        frame.draw_rectangle(static_cast<int>(x() - 3), static_cast<int>(y() + 3), 6, 6);
    }

    Vector Vector::multiply(Matrix &matrix) {
      Vector newVector;
      for (int i = 0; i < matrix.rows; i++) {
          float value = 0;
          for (int j = 0; j < data.size(); j++) {
              value += data[j] * matrix.data[i][j];
          }
          newVector.data[i] = value;
      }
      return newVector;
    }

    std::string Vector::toString() {
        std::string result = "";
        result.append(std::to_string(x()));
        result.append(" | ");
        result.append(std::to_string(y()));
        result.append(" | ");
        result.append(std::to_string(z()));

        return result;
    }
}