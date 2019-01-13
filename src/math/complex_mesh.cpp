#include <utility>

#include <utility>

//
// Created by Daan on 23/11/2018.
//

#include <math/complex_mesh.h>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace math {
    complex_mesh::complex_mesh() {
      model_matrix_ = std::make_unique<math::mat4>(1.f);
    }

    void complex_mesh::draw(ui::sdl::frame &frame, math::mat4 projection, math::mat4 view) {
      //   std::cout << "--------\n";
      for (const auto &face : faces) {
        for (int i = 0; i < face.size(); ++i) {
          vec4 point_1 = points[face[i]];
          vec4 point_2 = points[face[(i + 1) % face.size()]];

//        std::cout << point_1.toString();

          auto pvm = projection * view * model_matrix();

          point_1 = point_1.multiply(pvm);
          point_2 = point_2.multiply(pvm);

          if (point_1.w() < 0 || point_2.w() < 0) {
            break;
          }

          //    std::cout << std::to_string(point_1.w()) + "\n";
          //    std::cout << std::to_string(point_2.w()) + "\n";

          float width = 1.f;
          float height = 1.f;

          if (point_1.w() != 0) {
            point_1.x((width / 2.f) + (point_1.x() / point_1.w()) * (width / 2.f));
            point_1.y((height / 2.f) + (point_1.y() / point_1.w()) * (height / 2.f));
          }

          if (point_2.w() != 0) {
            point_2.x((width / 2.f) + (point_2.x() / point_2.w()) * (width / 2.f));
            point_2.y((height / 2.f) + (point_2.y() / point_2.w()) * (height / 2.f));
          }

          frame.drawLine(static_cast<int>(point_1.x()), static_cast<int>(point_1.y()),
                         static_cast<int>(point_2.x()), static_cast<int>(point_2.y()));
        }
      }
      //   std::cout << "----------\n";
    }

    void complex_mesh::multiply(mat4 &other) {
      complex_mesh newShape;
      for (int i = 0; i < points.size(); i++) {
        newShape.points.push_back(points[i].multiply(other));
      }
      this->points = newShape.points;
    }

    math::mat4 &complex_mesh::model_matrix() {
      model_matrix_ = std::make_unique<math::mat4>(1.f);
      model_matrix_->scale(scale_);

      model_matrix_->rotate_axis(rotation_.z(), {0, 0, 1});

      model_matrix_->rotate_axis(rotation_.y(), {0, 1, 0});

      model_matrix_->rotate_axis(rotation_.x(), {1, 0, 0});

      model_matrix_->translate(location_);

      return *model_matrix_;
    }

    void complex_mesh::location(vec4 location) {
      location_ = std::move(location);
    }

    vec4 &complex_mesh::location() {
      return location_;
    }
    void complex_mesh::rotation(vec4 rotation) {
      rotation_ = std::move(rotation);
    }

    vec4 &complex_mesh::rotation() {
      return rotation_;
    }

    void complex_mesh::scale(vec4 scale) {
      scale_ = std::move(scale);
    }

    vec4 &complex_mesh::scale() {
      return scale_;
    }
}