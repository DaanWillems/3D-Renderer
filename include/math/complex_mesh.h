#pragma once

#include <vector>
#include <memory>
#include "vec4.h"
#include "mat4.h"
#include "ui/sdl/frame.h"

namespace math {
    class complex_mesh: public ui::renderable  {
    public:
      complex_mesh();
      std::vector<vec4> points;
      // Dit zou een vec4 kunnen zijn, maar een float is niet precies genoeg voor indices
      std::vector<std::vector<int>> faces;
        void draw(ui::sdl::frame& frame, math::mat4 projection, math::mat4 view_) override;
        math::mat4& model_matrix() override;

        void location(vec4 location_);
        vec4& location();

        void rotation(vec4 rotation_);
        vec4& rotation();

        void scale(vec4 rotation_);
        vec4& scale();

        void multiply(mat4 &other);

    protected:
        std::unique_ptr<math::mat4> model_matrix_;
        vec4 location_{0.f, 0.f};
        vec4 rotation_{0.f, 0.f, 0.f};
        vec4 scale_{1.f, 1.f, 1.f};

        void draw_points(const vec4 &point_1, const vec4 &point_2, ui::sdl::frame &frame, const mat4 &pvm, vec4 color);
    };
}

