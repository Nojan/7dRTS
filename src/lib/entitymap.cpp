// associated header
#include "entitymap.h"


namespace core
{

void EntityMap::registerUnit(const TilePos& pos, std::size_t unitId)
{
  _units.insert({pos, unitId});
}


void EntityMap::eraseUnit(const TilePos& pos)
{
  _units.erase(pos);
}


std::size_t EntityMap::unit(const TilePos& pos) const
{
  auto it = _units.find(pos);
  if(it != std::end(_units))
  {
    return it->second;
  }
  else
  {
    return not_found;
  }
}


void EntityMap::clearUnits()
{
  _units.clear();
}


void EntityMap::registerDoor(const EdgePos& pos, std::size_t doorId)
{
  _doors.insert({pos, doorId});
}


std::size_t EntityMap::door(const EdgePos& pos) const
{
  auto it = _doors.find(pos);
  if(it != std::end(_doors))
  {
    return it->second;
  }
  else
  {
    return not_found;
  }
}

} // core
