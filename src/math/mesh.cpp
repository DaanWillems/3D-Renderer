//
// Created by Daan on 23/11/2018.
//

#include <math/mesh.h>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace math {
    mesh::mesh() {
        model_matrix_ = std::make_unique<math::mat4>(1.f);
    }

    void mesh::draw(ui::sdl::frame &frame, math::mat4 projection, math::mat4 view) {
        for (int i = 0; i < points.size() - 1; i++) {
            vec4 point_1 = points[i];
            vec4 point_2 = points[i + 1];

            auto pvm = projection * view * model_matrix();

            point_1 = point_1.multiply(pvm);
            point_2 = point_2.multiply(pvm);
            std::cout << "\n------------------\n";
            std::cout << pvm.toString();

            std::cout << "\n=--=-=-=--=\n";
            std::cout << point_1.toString() + "\n";
            std::cout << point_2.toString() + "\n";
            std::cout << "=--=-=-=--=\n";

            if (point_1.w() < 0 || point_2.w() < 0) {
                return;
            }

            if (point_1.w() != 0) {
                point_1.x((1.f / 2.f) + (point_1.x() / point_1.w()) * (1.f / 2.f));
                point_1.y((1.f / 2.f) + (point_1.y() / point_1.w()) * (1.f / 2.f));
            }

            if (point_2.w() != 0) {
                point_2.x((1.f / 2.f) + (point_2.x() / point_2.w()) * (1.f / 2.f));
                point_2.y((1.f / 2.f) + (point_2.y() / point_2.w()) * (1.f / 2.f));
            }

//            if(point_1.w() != 0) {
//                point_1.x(point_1.x() / point_1.w());
//                point_1.x(point_1.y() / point_1.w());
//            }
//
//            if(point_2.w() != 0) {
//                point_2.x(point_2.x() / point_2.w());
//                point_2.x(point_2.y() / point_2.w());
//            }
            std::cout << "\n=--=-=-=--=\n";
            std::cout << point_1.toString() + "\n";
            std::cout << point_2.toString() + "\n";
            std::cout << "=--=-=-=--=\n";
            frame.drawLine(point_1.x(), point_1.y(), point_2.x(), point_2.y());
        }
    }

    void mesh::multiply(mat4 &other) {
        mesh newShape;
        for (int i = 0; i < points.size(); i++) {
            newShape.points.push_back(points[i].multiply(other));
        }
        std::cout << newShape.points[0].toString();
        std::cout << this->points[0].toString().c_str();
        this->points = newShape.points;
    }

    std::string mesh::toString() const {
//        return std::accumulate(points.begin(), points.end(), std::string{""} ,[&](auto& result, vec4& cur) {
//            return result + cur.toString();
//        });
        return "";
    }

    math::mat4 &mesh::model_matrix() {
        model_matrix_ = std::make_unique<math::mat4>(1.f);
        model_matrix_->translate(location_);
        model_matrix_->scale(scale_);
      //  model_matrix_->rotate(rotation_.x(), {1.f, 0.f, 0.f});
        model_matrix_->rotate(rotation_.x(), {0.f, 1.f, 0.f});
        model_matrix_->rotate(rotation_.x(), {0.f, 0.f, 1.f});

        return *model_matrix_;
    }

    void mesh::location(vec4 location) {
        location_ = location;
    }

    vec4 &mesh::location() {
        return location_;
    }

    void mesh::rotation(vec4 rotation) {
        rotation_ = rotation;
    }

    vec4 &mesh::rotation() {
        return rotation_;
    }

    void mesh::scale(vec4 scale) {
        scale_ = scale;
    }

    vec4 &mesh::scale() {
        return scale_;
    }
}