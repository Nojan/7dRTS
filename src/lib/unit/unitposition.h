#ifndef UNITPOSITION_H
#define UNITPOSITION_H

// include
// core
#include "entityposition.h"

namespace core
{

class UnitPosition : public EntityPosition
{
public:
  UnitPosition(std::size_t eId, const Eigen::Vector2f& pos)
    : EntityPosition(eId, pos)
  { }
};

} // core

#endif // UNITPOSITION_H
