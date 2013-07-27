#include "pathfindingmap.h"


namespace core
{

PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  for(tile_index x = 0; x < tile_index(_nodes.width()); ++x)
  {
    for(tile_index y = 0; y < tile_index(_nodes.height()); ++y)
    {
      Node n;
      auto addNeighbor = [&](tile_index xoff, tile_index yoff)
      {
        if(_nodes.inGrid(x + xoff, y + yoff))
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
