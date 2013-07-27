#include "entityposition.h"

#include "entitymanager.h"
#include "entitymovement.h"
#include "gameworld.h"

EntityPosition::EntityPosition(size_t entityId, const Eigen::Vector2f position)
  : EntityModule(entityId)
  , _position(position)
{
}

Eigen::Vector2f EntityPosition::position() const
{
  return _position;
}

void EntityPosition::setPosition(const Eigen::Vector2f position)
{
  _position = position;
}

void EntityPosition::update()
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const EntityMovement* movementModule = entityManager.movementModule(entityId());
  if(movementModule)
  {
    _position = movementModule->position();
  }
}
