#ifndef UNITMOVEMENT_H
#define UNITMOVEMENT_H

// include
// core
#include "entitymovement.h"

namespace core
{

class UnitMovement : public EntityMovement
{
public:
  UnitMovement(std::size_t eId, float speedMax)
    : EntityMovement(eId, speedMax)
  { }
};

} // core

#endif // UNITMOVEMENT_H
