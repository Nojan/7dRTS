#ifndef GENERALMAP_H
#define GENERALMAP_H

// include
// std
#include <functional>
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


struct TilePos
{
  tile_index x, y;

  bool operator==(const TilePos& p) const
  {
    return x == p.x && y == p.y;
  }
};


struct EdgePos
{
  TilePos from, to;
};


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
  TilePos pos;
};


struct Door
{
  std::vector<EdgePos> edges;
};


struct Room
{
  enum class Type {None};

  std::vector<TilePos> tiles;
  std::vector<EdgePos> walls;
  Door door;
};



class GeneralMap
{
public:
  static GeneralMap fromGimpImage(const GimpImage& gImage);

public:
  // since we must copy tile, obstacles and doors we can pass it by value.
  // this allow compiler optimization and it's less verbose.
  GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
             std::vector<Door> doors, std::vector<Room> rooms);

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
  std::vector<Room> _rooms;
};

}


// hash functions
namespace std
{

template<>
struct hash<core::TilePos>
{
public:
  std::size_t operator()(const core::TilePos& s) const
  {
    return std::hash<core::tile_index>()(s.x);
        (std::hash<core::tile_index>()(s.y) << 1);
  }
};

} // std

#endif // GENERALMAP_H
