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
  enum class State {Idle, Move, MoveToFight, Fight};

public:
  EntityStateMachine(std::size_t entityId);
  virtual ~EntityStateMachine() {}

  void move(const Eigen::Vector2f& target);

  virtual void update(const int deltaMs) override;

private:
  State _state;
};

} // core

#endif // ENTITYSTATEMACHINE_H
