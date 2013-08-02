#ifndef UNITDAMAGE_H
#define UNITDAMAGE_H

// include
// core
#include "entitydamage.h"

class UnitDamage : public EntityDamage
{
public:
  UnitDamage(std::size_t eId, int hp)
    : EntityDamage(eId, hp)
  { }
};

#endif // UNITDAMAGE_H
