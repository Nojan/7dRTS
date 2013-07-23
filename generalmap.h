#ifndef GENERALMAP_H
#define GENERALMAP_H

// include
// std
#include <vector>
#include <limits>

// core
#include "grid.h"


// forward declaration

namespace core
{

// forward declaration
class GimpImage;


typedef unsigned int tile_index;


struct Tile
{
  enum class Type {Free, Obstacle, None};
  enum class Texture {Grass, Wall, Floor, Path, None};

  Tile()
    : type(Type::None)
    , texture(Texture::None)
  {}

  Tile(Type t, Texture tex)
    : type(t)
    , texture(tex)
  {}


  Type type;
  Texture texture;
};


struct Obstacle
{
  Obstacle()
    : x(std::numeric_limits<tile_index>::max())
    , y(std::numeric_limits<tile_index>::max())
  {}

  Obstacle(tile_index tx, tile_index ty)
    : x(tx)
    , y(ty)
  {}


  tile_index x, y;
};


struct Door
{
  Door()
    : from(std::numeric_limits<tile_index>::max())
    , to(std::numeric_limits<tile_index>::max())
  {}

  Door(tile_index f, tile_index t)
    : from(f)
    , to(t)
  {}


  tile_index from, to;
};



class GeneralMap
{
public:
  static GeneralMap&& fromGimpImage(const GimpImage& gImage);

public:
  // since we must copy tile, obstacles and doors we can pass it by value.
  // this allow compiler optimization and it's less verbose.
  GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
             std::vector<Door> doors);

  // accessors
  const Grid<Tile>& tileGrid() const
  {
    return _tileGrid;
  }

  const std::vector<Obstacle>& obstacles()
  {
    return _obstacles;
  }

  const std::vector<Door>& doors()
  {
    return _doors;
  }

private:
  Grid<Tile> _tileGrid;
  std::vector<Obstacle> _obstacles;
  std::vector<Door> _doors;
};

}

#endif // GENERALMAP_H
