#ifndef ENTITYSTATEMACHINE_H
#define ENTITYSTATEMACHINE_H
#include "pch.h"

#include "entitymodule.h"

class EntityStateMachine : public EntityModule
{
public:
  EntityStateMachine(size_t entityId);

  void update();
};

#endif // ENTITYSTATEMACHINE_H
