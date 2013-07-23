#include "entityposition.h"

#include "entitymanager.h"
#include "entitymovement.h"

EntityPosition::EntityPosition(size_t entityId)
  : EntityModule(entityId)
{
}

Eigen::Vector2f EntityPosition::position()
{
  return _position;
}

void EntityPosition::setPosition(const Eigen::Vector2f position)
{
  _position = position;
}

void EntityPosition::update()
{
  const EntityMovement* movementModule = EntityManager::Instance().movementModule(entityId());
  if(movementModule)
  {
    _position = movementModule->position();
  }
}
