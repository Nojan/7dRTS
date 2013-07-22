#ifndef GENERALMAP_H
#define GENERALMAP_H

// include
// std
#include <vector>
#include <limits>


// forward declaration
class EntityManager;

namespace core
{

typedef unsigned int tile_index;


struct Tile
{
  enum Type {Grass=0, Path, Floor, None};

  Tile()
    : type(None)
  {}

  Tile(Type t)
    : type(t)
  {}


  Type type;
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
  /// @todo add faction
  /// @todo add life
  /// @todo maybe door must be an entity ?
};


typedef std::vector<std::vector<Tile> > TileGrid;


class GeneralMap
{
public:
  // since we must copy tile, obstacles and doors we can pass it by value.
  // this allow compiler optimization and it's less verbose.
  GeneralMap(TileGrid tiles, std::vector<Obstacle> obstacles,
             std::vector<Door> doors, const EntityManager* entityManager);

  // accessors
  const TileGrid& tileGrid() const
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

  const EntityManager* entityManager() const
  {
    return _entityManager;
  }

private:
  TileGrid _tileGrid;
  std::vector<Obstacle> _obstacles;
  std::vector<Door> _doors;
  const EntityManager* _entityManager;
};

}

#endif // GENERALMAP_H
