#include <utility>

#include <game/game_object.h>
#include <ui/mesh_loader.h>

namespace game {
game_object::game_object(std::string model) : math::complex_mesh(ui::mesh_loader::make_mesh(std::move(model))) {
}
}