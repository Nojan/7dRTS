#ifndef PATHFINDINGMAP_H
#define PATHFINDINGMAP_H

// include
// std
#include <cmath>

#include <QDebug>
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

  std::size_t width() const;
  std::size_t height() const;

  double cost(const TilePos& from, const TilePos& to) const
  {
    return std::pow(double(from.x) - double(to.x), 2) +
        std::pow(double(from.y) - double(to.y), 2);
  }

  double heuristic(const TilePos& pos, const TilePos& obj) const
  {
    return std::pow(double(pos.x) - double(obj.x), 2) +
        std::pow(double(pos.y) - double(obj.y), 2);
  }

  const std::vector<TilePos>& neighbor(const TilePos& pos) const
  {
    return _nodes.at(pos.x, pos.y).neighbor;
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
