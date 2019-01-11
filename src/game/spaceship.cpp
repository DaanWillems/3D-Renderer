#include <game/spaceship.h>

game::projectile game::spaceship::shoot() {
  game::projectile projectile{};

  projectile.rotation(rotation());
  projectile.location(location());

  return projectile;
}
