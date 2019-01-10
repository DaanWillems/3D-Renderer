#include <ui/mesh_loader.h>
#include <bstd.h>
#include <sstream>
#include <iostream>
#include <math/vec4.h>

math::complex_mesh ui::mesh_loader::make_mesh(std::string object) const {
  math::complex_mesh mesh{};


  std::stringstream ss{object};

  char type{};
  while (ss >> type) {
    if (type == 'v') {
      float x{};
      float y{};
      float z{};
      if (ss >> x >> y >> z) {
        mesh.points.emplace_back(x, y, z, 1.f);
        continue;
      }
    } else if (type == 'f') {
      int v1{};
      int v2{};
      int v3{};
      if (ss >> v1 >> v2 >> v3) {
        mesh.faces.push_back({v1 - 1, v2 - 1, v3 - 1});
        continue;
      }
    }
    break;
  }


  return mesh;
}
