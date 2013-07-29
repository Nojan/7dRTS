// associated header
#include "pathfindingmap.h"

// include
// std
#include <unordered_set>


namespace core
{

struct SymetricWallHash
{
  std::size_t operator()(const EdgePos& wall) const
  {
    return std::hash<TilePos>()(wall.to) &
        std::hash<TilePos>()(wall.from);
  }
};



struct SymetricWallEqual
{
  bool operator()(const EdgePos& w1, const EdgePos& w2) const
  {
    return (w1.to == w2.to && w1.from == w2.from) ||
        (w1.from == w2.to && w1.to == w2.from);
  }
};



PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  std::unordered_set<EdgePos, SymetricWallHash, SymetricWallEqual> wallSet;

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
           (wallSet.find({curPos, canPos}) == std::end(wallSet)))
        {
          n.neighbor.push_back(canPos);
        }
      };
      auto addNeighborDiag = [&](tile_index xoff, tile_index yoff)
      {
        TilePos canPos = {x + xoff, y + yoff};
        TilePos w1Pos = {x + xoff, y};
        TilePos w2Pos = {x, y + yoff};
        if(_nodes.inGrid(canPos.x, canPos.y) &&
           (wallSet.find({curPos, w1Pos}) == std::end(wallSet)) &&
           (wallSet.find({curPos, w2Pos}) == std::end(wallSet)) &&
           (wallSet.find({canPos, w1Pos}) == std::end(wallSet)) &&
           (wallSet.find({canPos, w2Pos}) == std::end(wallSet)))
        {
          n.neighbor.push_back(canPos);
        }
      };

      addNeighbor(1, 0);
      addNeighborDiag(1, 1);
      addNeighborDiag(1, -1);
      addNeighbor(-1, 0);
      addNeighborDiag(-1, 1);
      addNeighborDiag(-1, -1);
      addNeighbor(0, 1);
      addNeighbor(0, -1);
      _nodes(x, y) = n;
    }
  }
}

} // core
