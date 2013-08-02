#ifndef UNITWEAPON_H
#define UNITWEAPON_H

// include
// core
#include "entityweapon.h"

class UnitWeapon : public EntityWeapon
{
public:
  UnitWeapon(size_t eId, int damage, float range, int fireRate)
    : EntityWeapon(eId, damage, range, fireRate)
  { }
};

#endif // UNITWEAPON_H
