//
// Created by Daan on 23/11/2018.
//

#ifndef RDALGEBRA2_SHAPE_H
#define RDALGEBRA2_SHAPE_H

#include <vector>
#include <memory>
#include "vec4.h"
#include "mat4.h"

namespace math {
    class shape: public ui::renderable  {
    public:
        shape();
        std::vector<vec4> points;
        void draw(ui::sdl::frame& frame) override;
        math::mat4& model_matrix() override;
        void multiply(mat4 &other);
        std::string toString() const;
    private:
        std::unique_ptr<math::mat4> model_matrix_;
    };
}

#endif //RDALGEBRA2_SHAPE_H
