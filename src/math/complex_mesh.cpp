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

          if (point_1.w() != 0) {
            point_1.x((1.f / 2.f) + (point_1.x() / point_1.w()) * (1.f / 2.f));
            point_1.y((1.f / 2.f) + (point_1.y() / point_1.w()) * (1.f / 2.f));
          }

          if (point_2.w() != 0) {
            point_2.x((1.f / 2.f) + (point_2.x() / point_2.w()) * (1.f / 2.f));
            point_2.y((1.f / 2.f) + (point_2.y() / point_2.w()) * (1.f / 2.f));
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
//    std::cout << newShape.points[0].toString();
//    std::cout << this->points[0].toString().c_str();
      this->points = newShape.points;
    }

    std::string complex_mesh::toString() const {
//        return std::accumulate(points.begin(), points.end(), std::string{""} ,[&](auto& result, vec4& cur) {
//            return result + cur.toString();
//        });
      return "";
    }

    math::mat4 &complex_mesh::model_matrix() {
      model_matrix_ = std::make_unique<math::mat4>(1.f);
      model_matrix_->translate(location_);

      //model_matrix_->rotate_axis(rotation_.x()/50, {0.f, 0.f, 1.f});
      // model_matrix_->rotate_axis(45, {0.f, 0.f, 1.f});
      model_matrix_->rotate_axis(45, {1.f, 0.f, 0.f});
      //model_matrix_->rotate_axis(rotation_.x(), {0.f, 1.f, 1.f});
      //   model_matrix_->rotate(0, {0.f, 1.f, 0.f});
      //model_matrix_->rotate(rotation_.x(), {1.f, 0.f, 0.f});

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