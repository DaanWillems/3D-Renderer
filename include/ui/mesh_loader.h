#pragma once

#include <math/complex_mesh.h>

namespace ui {
  class mesh_loader {
  public:
    static math::complex_mesh make_mesh(std::string object);
  };
}