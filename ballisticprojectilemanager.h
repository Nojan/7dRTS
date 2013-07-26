#ifndef BALLISTICPROJECTILEMANAGER_H
#define BALLISTICPROJECTILEMANAGER_H
#include "pch.h"

#include <vector>

namespace core {

class BallisticProjectile
{
public:
  BallisticProjectile(Eigen::Vector2f start, Eigen::Vector2f orientation, int damage);

  Eigen::Vector2f position() const;
  Eigen::Vector2f orientation() const;
  int damage() const;

  void evolve(float deltas);

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _damage;
};

class BallisticProjectileManager
{
public:
  BallisticProjectileManager();

  void addProjectile(BallisticProjectile* projectile);

  void evolve(const float deltas);

private:
  std::vector<BallisticProjectile*> _projectiles;
};

} //namespace core
#endif // BALLISTICPROJECTILEMANAGER_H
