#ifndef GENERALMAP_H
#define GENERALMAP_H

// include
// std
#include <vector>

// core
#include "grid.h"
#include "maptypes.h"


// forward declaration

namespace core
{

// forward declaration
class GimpImage;


class GeneralMap
{
public:
  static GeneralMap fromGimpImage(const GimpImage& gImage);

public:
  // since we must copy tile, obstacles and doors we can pass it by value.
  // this allow compiler optimization and it's less verbose.
  GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
             std::vector<Room> rooms, Rampart rampart);

  // accessors
  const Grid<Tile>& tileGrid() const
  {
    return _tileGrid;
  }

  const std::vector<Obstacle>& obstacles() const
  {
    return _obstacles;
  }

  const std::vector<Room>& rooms() const
  {
    return _rooms;
  }

  const Rampart& rampart() const
  {
    return _rampart;
  }

private:
  Grid<Tile> _tileGrid;
  std::vector<Obstacle> _obstacles;
  std::vector<Room> _rooms;
  Rampart _rampart;
};

} // core


#endif // GENERALMAP_H
