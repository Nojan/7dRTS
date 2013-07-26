#include "pathfindingmap.h"


namespace core
{

PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  for(std::size_t x = 0; x < _nodes.width(); ++x)
  {
    for(std::size_t y = 0; y < _nodes.height() ; ++y)
    {
      Node n;
      auto addNeighbor = [&](int xoff, int yoff)
      {
        if(_nodes.inGrid(int(x) + xoff, int(y) + yoff))
        {
          n.neighbor.push_back({tile_index(x + xoff), tile_index(y + yoff)});
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
      _nodes(x, y) = n;
    }
  }
}

} // core
