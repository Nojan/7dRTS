// associated header
#include "pathfindingmap.h"

// include
// std
#include <unordered_set>


namespace core
{

PathFindingMap::PathFindingMap()
{ }


PathFindingMap::PathFindingMap(const GeneralMap* map)
  : _nodes(map->tileGrid().width(), map->tileGrid().height())
{
  std::unordered_set<EdgePos, std::symetric_hash<core::EdgePos>,
      std::symetric_equal<core::EdgePos>> wallSet;

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


std::size_t PathFindingMap::width() const
{
  return _nodes.width();
}


std::size_t PathFindingMap::height() const
{
  return _nodes.height();
}

} // core
