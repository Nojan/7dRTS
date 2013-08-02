#ifndef ENTITYSTATEMACHINE_H
#define ENTITYSTATEMACHINE_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"

namespace core
{

class EntityStateMachine : public EntityModule
{
public:
  EntityStateMachine(std::size_t entityId);

  void update();
};

} // core

#endif // ENTITYSTATEMACHINE_H
