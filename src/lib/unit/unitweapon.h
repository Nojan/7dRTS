#ifndef UNITWEAPON_H
#define UNITWEAPON_H

// include
// core
#include "entityweapon.h"

namespace core
{

class UnitWeapon : public EntityWeapon
{
public:
  UnitWeapon(std::size_t eId, int damage, float range, int fireRate)
    : EntityWeapon(eId, damage, range, fireRate)
  { }
};

} // core

#endif // UNITWEAPON_H
