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
      std::vector<int> faces;
      int v{};
      while (ss >> v) {
        faces.push_back(v - 1);
      }
      if (!faces.empty()) {
        mesh.faces.push_back(faces);
        ss.clear();
        continue;
      } else {
        std::cout << "WTF";
        break;
      }
      std::cout << "WTF2";
    }
    std::cout << "WTF3";
    break;
  }


  return mesh;
}
