#ifndef ENTITYMAP_H
#define ENTITYMAP_H

// include
// std
#include <unordered_map>

// core
#include "maptypes.h"

namespace core
{

class EntityMap
{
public:
  const std::size_t not_found = std::numeric_limits<std::size_t>::max();

public:
  void registerUnit(const TilePos& pos, std::size_t unitId);
  void eraseUnit(const TilePos& pos);
  std::size_t unit(const TilePos& pos) const;
  void clearUnits();

  void registerDoor(const EdgePos& pos, std::size_t doorId);
  std::size_t door(const EdgePos& pos) const;

private:
  /// @todo multi map since unit can fight on the same tile ?
  std::unordered_map<TilePos, std::size_t> _units;
  std::unordered_map<EdgePos, std::size_t,
    std::symetric_hash<core::EdgePos>,
    std::symetric_equal<core::EdgePos>> _doors;
};

} // core

#endif // ENTITYMAP_H
