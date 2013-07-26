#include "ballisticprojectilemanager.h"

using namespace core;

BallisticProjectile::BallisticProjectile(Eigen::Vector2f start, Eigen::Vector2f orientation, int damage)
  : _position(start)
  , _orientation(orientation)
  , _damage(damage)
{
}

Eigen::Vector2f BallisticProjectile::position() const
{
  return _position;
}

Eigen::Vector2f BallisticProjectile::orientation() const
{
  return _orientation;
}

int BallisticProjectile::damage() const
{
  return _damage;
}

void BallisticProjectile::evolve(float deltas)
{
  _position += _orientation*25.f*deltas;
}

BallisticProjectileManager::BallisticProjectileManager()
{
}

void BallisticProjectileManager::addProjectile(BallisticProjectile *projectile)
{
  _projectiles.push_back(projectile);
}

void BallisticProjectileManager::evolve(const float deltas)
{
  BallisticProjectile* projectile;
  for(size_t i =0; i< _projectiles.size(); ++i)
  {
    projectile = _projectiles.at(i);
    assert(projectile);
    projectile->evolve(deltas);
  }
}
