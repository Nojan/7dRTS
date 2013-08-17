#ifndef DOORSTATEMACHINE_H
#define DOORSTATEMACHINE_H

// include
// core
#include "entitystatemachine.h"

namespace core
{

class DoorStateMachine : public EntityStateMachine
{
public:
  DoorStateMachine(std::size_t entityId);

  void open();
  void lock();

  virtual void update(const int deltaMs);

private:
  bool _open;
  int _openQuery;
};

} // core

#endif // DOORSTATEMACHINE_H
