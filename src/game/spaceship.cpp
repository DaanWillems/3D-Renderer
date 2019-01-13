#include <utility>

#include <game/spaceship.h>
#include <iostream>
#include <cmath>

game::projectile game::spaceship::shoot(int id) {
  game::projectile projectile{id};

  projectile.rotation(rotation());
  projectile.location(location());

  return projectile;
}

void game::spaceship::update(float delta_time) {

  rotation({pitch_, yaw_, roll_});

  math::mat4 rotate_{1.f};

  rotate_.rotate_axis(roll_, {0.f, 0.f, 1.f});
  rotate_.rotate_axis(yaw_, {0.f, 1.f, 0.f});
  rotate_.rotate_axis(pitch_, {1.f, 0.f, 0.f});

  auto acc = acceleration_.multiply(rotate_);

  //Apply accelaration
  velocity_ += acc;
  //velocity_.z(velocity_.z() + acceleration_.z());

  //Apply friction
  if(!decoupled_) { //Friction will help go the vehicle go the direction it is facing, when deoucpled is enabled the spaceship behaves more realistically
    velocity_ = velocity_ * (1 - (friction_ * delta_time));
  }

  //Truncate velocity;
  auto truncated_velocity = math::truncate(velocity_, max_speed_);

  location(location() + ((truncated_velocity*(5*delta_time)) * -1));
}

void game::spaceship::acceleration(math::vec4 &&acc) {
  acceleration_ = std::move(acc);
}

math::vec4 game::spaceship::acceleration() {
  return acceleration_;
}

float game::spaceship::yaw() {
  return yaw_;
}

void game::spaceship::yaw(float yaw) {
  yaw_ = yaw;
}

float game::spaceship::roll() {
  return roll_;
}

void game::spaceship::roll(float roll) {
  roll_ = roll;
}

float game::spaceship::pitch() {
  return pitch_;
}

void game::spaceship::pitch(float pitch) {
  pitch_ = pitch;
}

bool game::spaceship::decoupled() {
  return decoupled_;
}

void game::spaceship::decoupled(bool uncoupled) {
  decoupled_ = uncoupled;
}

math::vec4 game::spaceship::collision_location() {
  return location();
}

float game::spaceship::collision_radius() {
  return 20.f;
}
