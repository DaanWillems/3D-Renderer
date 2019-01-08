//
// Created by Daan on 23/11/2018.
//

#include <math/shape.h>
#include <iostream>
#include <algorithm>
#include <numeric>

namespace math {
    void shape::draw(ui::sdl::frame& frame) {
        for(int i = 0; i < points.size()-1; i++) {
           frame.drawLine(points[i].x(), points[i].y(), points[i+1].x(), points[i+1].y());
        }
    }

    void shape::multiply(mat4 &other) {
        shape newShape;
        for(int i = 0; i < points.size(); i++) {
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
}