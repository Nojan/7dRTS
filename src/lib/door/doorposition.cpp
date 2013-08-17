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
  // we must fill diagonal case
  for(const EdgePos& e1: _edges)
  {
    for(const EdgePos& e2: _edges)
    {
      if((Eigen::Vector2i(e1.from) - Eigen::Vector2i(e2.to)).array().abs().sum() <= 2)
      {
        eMap.registerDoor({e1.from, e2.to}, entityId);
      }
    }
  }
}


void DoorPosition::update(const int )
{ }

} // core
