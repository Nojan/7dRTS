#ifndef ENTITYWEAPON_H
#define ENTITYWEAPON_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"

namespace core
{

class WeaponTarget
{
public:
  WeaponTarget(std::size_t entityId);

  size_t targetId() const;
private:
  size_t _target;
};

class EntityWeapon : public EntityModule
{
public:
  EntityWeapon(std::size_t entityId, int damage, float range, int fireRate);

  void update(int deltaMs);

  void setTarget(WeaponTarget * target);

  bool canShootAt(const Eigen::Vector2f& position) const;
  void shootAt(const Eigen::Vector2f& position);

  virtual void processDeadEntity(const std::size_t entityId);

private:
  int _damagePower;
  float _range;
  int _fireRate;
  int _fireRateCurrent;
  WeaponTarget * _target;
};

} // core

#endif // ENTITYWEAPON_H
