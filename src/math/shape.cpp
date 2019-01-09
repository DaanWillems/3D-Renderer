//
// Created by Daan on 23/11/2018.
//

#include <math/shape.h>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace math {
    shape::shape() {
        model_matrix_ = std::make_unique<math::mat4>(1.f);

        auto vectorScale = math::vec4{2.f, 2.f, 2.f};
        auto vectorTranslate = math::vec4{80.f, 80.f, 80.f};

        model_matrix_->translate(vectorTranslate);
        model_matrix_->rotate(40, vec4(1, 0, 0));
        model_matrix_->rotate(40, vec4(0, 0, 1));
    }

    void shape::draw(ui::sdl::frame &frame) {
        for (int i = 0; i < points.size() - 1; i++) {
            vec4 point_1 = points[i];
            vec4 point_2 = points[i+1];

            point_1 = point_1.multiply(model_matrix());
            point_2 = point_2.multiply(model_matrix());

            frame.drawLine(point_1.x(), point_1.y(), point_2.x(), point_2.y());
        }
    }

    void shape::multiply(mat4 &other) {
        shape newShape;
        for (int i = 0; i < points.size(); i++) {
            newShape.points.push_back(points[i].multiply(other));
        }
        std::cout << newShape.points[0].toString();
        std::cout << this->points[0].toString().c_str();
        this->points = newShape.points;
    }

    std::string shape::toString() const {
//        return std::accumulate(points.begin(), points.end(), std::string{""} ,[&](auto& result, vec4& cur) {
//            return result + cur.toString();
//        });
        return "";
    }

    math::mat4 &shape::model_matrix() {
        return *model_matrix_;
    }


}