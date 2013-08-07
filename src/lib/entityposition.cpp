// associated header
#include "entityposition.h"

// include
// core
#include "constantes.h"
#include "entitymanager.h"
#include "entitymovement.h"
#include "gameworld.h"

namespace core
{

EntityPosition::EntityPosition(std::size_t entityId, const Eigen::Vector2f& position)
  : EntityModule(entityId)
  , _position(position)
  , _tilePosition(tileFromPixel(position.cast<int>()))
  , _size(core::tileSizef)
{
}


const Eigen::Vector2f& EntityPosition::position() const
{
  return _position;
}


const TilePos& EntityPosition::tilePosition() const
{
  return _tilePosition;
}


void EntityPosition::setPosition(const Eigen::Vector2f& position)
{
  _position = position;
}

float EntityPosition::size() const
{
  return _size;
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

} // core
