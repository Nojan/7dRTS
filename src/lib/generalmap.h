#ifndef GENERALMAP_H
#define GENERALMAP_H

// include
// pch
#include "pch.h"

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


typedef int tile_index;


struct TilePos
{
  tile_index x, y;

  bool operator==(const TilePos& p) const
  {
    return x == p.x && y == p.y;
  }

  bool operator<(const TilePos& p) const
  {
    return x < p.x || ((x == p.x) && (y < p.y));
  }

  operator Eigen::Vector2i() const
  {
    return Eigen::Vector2i(x, y);
  }
};


struct EdgePos
{
  TilePos from, to;


  Eigen::Vector2i direction() const
  {
    return Eigen::Vector2i(to) - Eigen::Vector2i(from);
  }

  bool operator==(const EdgePos& p) const
  {
    return from == p.from && to == p.to;
  }

  bool operator<(const EdgePos& p) const
  {
    return from < p.from || ((from == p.from) && (to < p.to));
  }
};


Eigen::Vector2i pixelTopLeft(const TilePos& pos);
Eigen::Vector2i pixelTopLeft(const EdgePos& pos);
Eigen::Vector2i pixelCenter(const TilePos& pos);
Eigen::Vector2i pixelCenter(const EdgePos& pos);


struct Tile
{
  enum class Type {Free, Obstacle, None};
  enum class Texture {Grass, Rampart, Floor, Path, None};

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


class Door
{
public:
  Door();
  Door(std::vector<EdgePos> edges);
  Door& operator=(std::vector<EdgePos> edges);

  const std::vector<EdgePos>& edges() const
  {
    return _edges;
  }

  Eigen::Vector2i center() const;

private:
  void sort();

private:
  std::vector<EdgePos> _edges;
};


struct Room
{
  enum class Type {None};

  std::vector<TilePos> tiles;
  std::vector<EdgePos> walls;
  std::vector<Door> doors;
};


struct Rampart
{
  std::vector<TilePos> tiles;
  std::vector<EdgePos> walls;
};



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


template<>
struct hash<core::EdgePos>
{
public:
  std::size_t operator()(const core::EdgePos& s) const
  {
    return std::hash<core::TilePos>()(s.from);
        (std::hash<core::TilePos>()(s.to) << 1);
  }
};

} // std

#endif // GENERALMAP_H
