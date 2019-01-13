#pragma once

#include <game/game_object.h>
#include <game/cube.h>
#include <game/projectile.h>
#include <math/collidable.h>

namespace game{
class spaceship : public game_object, public math::collidable {
public:
  spaceship() : game_object(game::paperplane2) {
    scale({150.f, 150.f, 150.f});
  }

  void update(float delta_time);

  void acceleration(math::vec4&&);
  math::vec4 acceleration();

  float yaw();
  void yaw(float yaw);

  float roll();
  void roll(float roll);

  bool decoupled();
  void decoupled(bool);

  math::vec4 collision_location() override;
  float collision_radius() override;

  float pitch();
  void pitch(float pitch);
  projectile shoot(int id);

private:
    float max_speed_{3.f};
    float friction_{0.50f};
    math::vec4 velocity_{0.f, 0.f, 0.0f};
    math::vec4 acceleration_{0.f, 0.f, 0.f};
    float yaw_{0.f};
    float roll_{0.f};
    float pitch_{0.f};
    bool decoupled_ = false;
};
}