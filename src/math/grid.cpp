//
// Created by solaw on 05/11/2018.
//

#include <math/grid.h>

void math::grid::draw(ui::sdl::frame &frame) {
    frame.drawLine(0, 0, 320, 0);
    frame.drawLine(0, 0, 0, 320);
    frame.drawLine(0, 0, -320, 0);
    frame.drawLine(0, 0, 0, -320);
}
