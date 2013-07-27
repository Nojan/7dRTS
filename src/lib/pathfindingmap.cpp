// associated header
#include "pathfindingmap.h"

// include
// std
#include <unordered_set>


namespace core
{

PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  std::unordered_set<EdgePos> wallSet;

  for(const EdgePos& w: map->rampart().walls)
  {
    wallSet.insert(w);
  }

  for(const Room& room: map->rooms())
  {
    for(const EdgePos& w: room.walls)
    {
      wallSet.insert(w);
    }
  }

  for(tile_index x = 0; x < tile_index(_nodes.width()); ++x)
  {
    for(tile_index y = 0; y < tile_index(_nodes.height()); ++y)
    {
      Node n;
      TilePos curPos = {x, y};
      auto addNeighbor = [&](tile_index xoff, tile_index yoff)
      {
        TilePos canPos = {x + xoff, y + yoff};
        if(_nodes.inGrid(canPos.x, canPos.y) &&
           (wallSet.find({curPos, canPos}) == std::end(wallSet)) &&
           (wallSet.find({canPos, curPos}) == std::end(wallSet)))
        {
          n.neighbor.push_back(canPos);
        }
      };
      auto addNeighborDiag = [&](tile_index xoff, tile_index yoff,
          tile_index w1_xoff, tile_index w1_yoff,
          tile_index w2_xoff, tile_index w2_yoff)
      {
        TilePos canPos = {x + xoff, y + yoff};
        TilePos w1Pos = {x + w1_xoff, y + w1_yoff};
        TilePos w2Pos = {x + w2_xoff, y + w2_yoff};
        if(_nodes.inGrid(canPos.x, canPos.y) &&
           (wallSet.find({curPos, w1Pos}) == std::end(wallSet)) &&
           (wallSet.find({w1Pos, curPos}) == std::end(wallSet)) &&
           (wallSet.find({curPos, w2Pos}) == std::end(wallSet)) &&
           (wallSet.find({w2Pos, curPos}) == std::end(wallSet)))
        {
          n.neighbor.push_back(canPos);
        }
      };

      addNeighbor(1, 0);
      addNeighborDiag(1, 1, 1, 0, 0, 1);
      addNeighborDiag(1, -1, 1, 0, 0, -1);
      addNeighbor(-1, 0);
      addNeighborDiag(-1, 1, -1, 0, 0, 1);
      addNeighborDiag(-1, -1, -1, 0, 0, -1);
      addNeighbor(0, 1);
      addNeighbor(0, -1);
      _nodes(x, y) = n;
    }
  }
}

} // core
