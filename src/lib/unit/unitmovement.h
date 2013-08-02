#ifndef UNITMOVEMENT_H
#define UNITMOVEMENT_H

// include
// core
#include "entitymovement.h"

class UnitMovement : public EntityMovement
{
public:
  UnitMovement(size_t eId, float speedMax)
    : EntityMovement(eId, speedMax)
  { }
};

#endif // UNITMOVEMENT_H
