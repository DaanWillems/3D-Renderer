//
// Created by solaw on 05/11/2018.
//

#include <math/Grid.h>

#include "../../include/math/Grid.h"

void math::Grid::draw(ui::sdl::Frame &frame) {
    frame.drawLine(0, 0, 320, 0);
    frame.drawLine(0, 0, 0, 320);
    frame.drawLine(0, 0, -320, 0);
    frame.drawLine(0, 0, 0, -320);
}
