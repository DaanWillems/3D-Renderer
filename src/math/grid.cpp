//
// Created by solaw on 05/11/2018.
//

#include <math/mat4.h>
#include <math/grid.h>

void math::grid::draw(ui::sdl::frame &frame, math::mat4 projection, math::mat4 view_) {
    frame.drawLine(0, 0, 320, 0);
    frame.drawLine(0, 0, 0, 320);
    frame.drawLine(0, 0, -320, 0);
    frame.drawLine(0, 0, 0, -320);
}
