#ifndef UNITDAMAGE_H
#define UNITDAMAGE_H

// include
// core
#include "entitydamage.h"

namespace core
{

class UnitDamage : public EntityDamage
{
public:
  UnitDamage(std::size_t eId, int hp)
    : EntityDamage(eId, hp)
  { }
};

} // core

#endif // UNITDAMAGE_H
