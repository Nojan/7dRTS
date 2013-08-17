// associated header
#include "unitposition.h"

// include
// core
#include "gameworld.h"

namespace core
{

void UnitPosition::update(const int deltaMs)
{
  TilePos oldP = _tilePosition;
  EntityPosition::update(deltaMs);
  if(oldP != _tilePosition)
  {
    EntityMap& eMap = gameworld().entityMap();
    eMap.eraseUnit(oldP);
    eMap.registerUnit(_tilePosition, entityId());
  }
}

} // core
