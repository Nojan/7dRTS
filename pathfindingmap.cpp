#include "pathfindingmap.h"

namespace core
{

PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  for(std::size_t x = 0; x < _nodes.width(); ++x)
  {
    for(std::size_t y = 0; y < _nodes.height(); ++y)
    {
      Node n;
      auto addNeighbor = [&](std::size_t xoff, std::size_t yoff)
      {
        if(_nodes.inGrid(x + xoff, y + yoff))
        {
            n.neighbor.push_back({tile_index(x + xoff), tile_index(yoff)});
        }
      };

      addNeighbor(1, 0);
      addNeighbor(1, 1);
      addNeighbor(1, -1);
      addNeighbor(-1, 0);
      addNeighbor(-1, 1);
      addNeighbor(-1, -1);
      addNeighbor(0, 1);
      addNeighbor(0, -1);
    }
  }
}

} // core
