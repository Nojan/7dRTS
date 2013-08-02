#ifndef UNITSTATEMACHINE_H
#define UNITSTATEMACHINE_H

// include
// core
#include "entitystatemachine.h"

class UnitStateMachine : public EntityStateMachine
{
public:
  UnitStateMachine(std::size_t eId)
    : EntityStateMachine(eId)
  { }
};

#endif // UNITSTATEMACHINE_H
