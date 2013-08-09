// associated header
#include "doorstatemachine.h"

// include
// core
#include "doorgraphicholder.h"
#include "gameworld.h"

namespace core
{

DoorStateMachine::DoorStateMachine(std::size_t entityId)
  : EntityStateMachine(entityId)
  , _open(false)
  , _openQuery(0)
{
}


void DoorStateMachine::open()
{
  ++_openQuery;
}


void DoorStateMachine::lock()
{
  assert(_openQuery > 0);
  --_openQuery;
}


void DoorStateMachine::update()
{
  EntityManager& entityManager = gameworld().entityManager();
  DoorGraphicHolder* dgh = dynamic_cast<DoorGraphicHolder*>(
        entityManager.GraphicHolderModule(entityId()));
  assert(dgh);

  if(_openQuery > 0)
  {
    dgh->openning(true);
  }
  else
  {
    dgh->openning(false);
  }
}

} // core
