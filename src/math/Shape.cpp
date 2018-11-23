//
// Created by Daan on 23/11/2018.
//

#include <math/Shape.h>
#include <iostream>

namespace math {
    void Shape::draw(ui::sdl::Frame& frame) {
        for(int i = 0; i < points.size()-1; i++) {
           frame.drawLine(points[i].x(), points[i].y(), points[i+1].x(), points[i+1].y());
        }
    }

    void Shape::multiply(Matrix &other) {
        Shape newShape;
        for(int i = 0; i < points.size(); i++) {
            newShape.points.push_back(points[i].multiply(other));
        }
        this->points = newShape.points;
    }
}