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

    void mesh::draw(ui::sdl::frame &frame, math::mat4 projection) {
        for (int i = 0; i < points.size() - 1; i++) {
            vec4 point_1 = points[i];
            vec4 point_2 = points[i+1];

            point_1 = point_1.multiply(model_matrix());
            point_1 = point_1.multiply(projection);

            point_2 = point_2.multiply(model_matrix());
            point_2 = point_2.multiply(projection);

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
        model_matrix_->rotate(rotation_.x(), {0.f, 0.f, 1.f});
        model_matrix_->rotate(rotation_.y(), {0.f, 1.f, 0.f});
        model_matrix_->rotate(rotation_.z(), {1.f, 0.f, 0.f});

        return *model_matrix_;
    }

    void mesh::location(vec4 location) {
        location_ = location;
    }

    vec4& mesh::location() {
        return location_;
    }

    void mesh::rotation(vec4 rotation) {
        rotation_ = rotation;
    }

    vec4 &mesh::rotation() {
        return rotation_;
    }
}