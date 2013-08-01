#ifndef MAPTYPES_H
#define MAPTYPES_H

// include
// std
#include <vector>

// Eigen
#include <Eigen/Eigen>


namespace core
{

typedef int tile_index;


struct TilePos
{
  tile_index x, y;


  TilePos()
    : x(-1)
    , y(-1)
  { }

  TilePos(tile_index xp, tile_index yp)
    : x(xp)
    , y(yp)
  { }

  TilePos(const Eigen::Vector2i& pos)
    : x(pos.x())
    , y(pos.y())
  { }

  TilePos& operator=(const Eigen::Vector2i& pos)
  {
    x = pos.x();
    y = pos.y();
    return *this;
  }

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

TilePos tileFromPixel(const Eigen::Vector2i& pix);


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

} // core


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

#endif // MAPTYPES_H
