#pragma once

#include <math/complex_mesh.h>

namespace ui {
  class mesh_loader {
  public:
    math::complex_mesh make_mesh(std::string object) const;
  };
}