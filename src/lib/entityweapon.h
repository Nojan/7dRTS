#ifndef ENTITYWEAPON_H
#define ENTITYWEAPON_H
#include "pch.h"

#include "entitymodule.h"

class WeaponTarget
{
public:
  WeaponTarget(size_t entityId);

  size_t targetId() const;
private:
  size_t _target;
};

class EntityWeapon : public EntityModule
{
public:
  EntityWeapon(size_t entityId);

  void update(int deltaMs);

  void setTarget(WeaponTarget * target);

  bool canShootAt(Eigen::Vector2f position) const;
  void shootAt(Eigen::Vector2f position);

private:
  int _damagePower;
  float _range;
  int _fireRate;
  int _fireRateCurrent;
  WeaponTarget * _target;
};

#endif // ENTITYWEAPON_H
