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
    class mesh: public ui::renderable  {
    public:
        mesh();
        std::vector<vec4> points;
        void draw(ui::sdl::frame& frame, math::mat4 projection) override;
        math::mat4& model_matrix() override;

        void location(vec4 location_);
        vec4& location();

        void rotation(vec4 rotation_);
        vec4& rotation();

        void multiply(mat4 &other);
        std::string toString() const;
    private:
        std::unique_ptr<math::mat4> model_matrix_;
        vec4 location_{0.f, 0.f};
        vec4 rotation_{0.f, 0.f, 0.f};
    };
}

#endif //RDALGEBRA2_SHAPE_H
