//
// Created by Daan on 05/11/2018.
//

#include <math/vector.h>

namespace math {

    math::vector::vector() {
        data.push_back(0.f);
        data.push_back(0.f);
        data.push_back(0.f);
    }

    math::vector::vector(float x, float y) {
        data.push_back(x);
        data.push_back(y);
    }

    math::vector::vector(float x, float y, float z) {
        data.push_back(x);
        data.push_back(y);
        data.push_back(z);
    }

    float vector::x() {
        return data[0];
    }

    float vector::y() {
        return data[1];
    }

    float vector::z() {
        return data[2];
    }

    vector vector::add(math::vector vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] += vector.data[i];
        }
        return *this;
    }

    vector vector::substract(math::vector vector) {
        for (int i = 0; i < data.size(); i++) {
            data[i] -= vector.data[i];
        }
        return *this;
    }

    void vector::invert() {
        for (float &i : data) {
            i = -i;
        }
    }

    vector vector::operator+(const math::vector other) {
        vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] + other.data[i];
        }
        return vector;
    }

    vector vector::operator-(const math::vector other) {
        vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] - other.data[i];
        }
        return vector;
    }

    vector vector::operator*(const float scale) {
        vector vector;
        for (int i = 0; i < data.size(); i++) {
            vector.data[i] = data[i] * scale;
        }
        return vector;
    }

    vector vector::operator*=(const float scale) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = data[i] * scale;
        }
        return *this;
    }

    vector vector::operator+=(const math::vector other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] + other.data[i];
        }
        return *this;
    }

    vector vector::operator-=(const math::vector other) {
        for (int i = 0; i < data.size(); i++) {
            data[i] = this->data[i] - other.data[i];
        }
        return *this;
    }

    void vector::draw(ui::sdl::frame &frame) {
        frame.draw_rectangle(static_cast<int>(x() - 3), static_cast<int>(y() + 3), 6, 6);
    }

    vector vector::multiply(mat4 &matrix) {
      vector newvector;
      for (int i = 0; i < matrix.rows; i++) {
          float value = 0;
          for (int j = 0; j < data.size(); j++) {
              value += data[j] * matrix.data[i][j];
          }
          newvector.data[i] = value;
      }
      return newvector;
    }

    std::string vector::toString() {
        std::string result = "";
        result.append(std::to_string(x()));
        result.append(" | ");
        result.append(std::to_string(y()));
        result.append(" | ");
        result.append(std::to_string(z()));

        return result;
    }
}