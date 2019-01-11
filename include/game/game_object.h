#pragma once

#include <math/complex_mesh.h>
namespace game {
class game_object : public math::complex_mesh {
public:
  explicit game_object(std::string model);
private:

};
}