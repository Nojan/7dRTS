// associated header
#include "doorposition.h"

// include
// core
#include "gameworld.h"

namespace core
{

DoorPosition::DoorPosition(std::size_t entityId, const Eigen::Vector2f& centerPos,
                           std::vector<EdgePos> edges)
  : EntityPosition(entityId, centerPos)
  , _edges(std::move(edges))
{
  EntityMap& eMap = gameworld().entityMap();
  for(const EdgePos& e: _edges)
  {
    eMap.registerDoor(e, entityId);
  }
}


void DoorPosition::update()
{ }

} // core
