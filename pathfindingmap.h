#ifndef PATHFINDINGMAP_H
#define PATHFINDINGMAP_H

// include
// std
#include <cmath>

// core
#include "generalmap.h" // not needed if we separate TilePos
#include "grid.h"

namespace core
{

class PathFindingMap
{
public:
  typedef TilePos index_t;

public:
  PathFindingMap(const GeneralMap* map);

  double cost(const TilePos& from, const TilePos& to) const
  {
    return std::pow(from.x - to.x, 2) + std::pow(from.y - to.y, 2);
  }

  double heuristic(const TilePos& pos, const TilePos& obj) const
  {
    return std::pow(pos.x - obj.x, 2) + std::pow(pos.y - obj.y, 2);
  }

  const std::vector<TilePos>& neighbor(const TilePos& pos) const
  {
    return _nodes(pos.x, pos.y).neighbor;
  }

private:
  struct Node
  {
    std::vector<TilePos> neighbor;
  };

private:
  Grid<Node> _nodes;
};

} // core

#endif // PATHFINDINGMAP_H
