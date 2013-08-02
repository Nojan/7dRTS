#ifndef UNITSTATEMACHINE_H
#define UNITSTATEMACHINE_H

// include
// core
#include "entitystatemachine.h"

namespace core
{

class UnitStateMachine : public EntityStateMachine
{
public:
  UnitStateMachine(std::size_t eId)
    : EntityStateMachine(eId)
  { }
};

} // core

#endif // UNITSTATEMACHINE_H
