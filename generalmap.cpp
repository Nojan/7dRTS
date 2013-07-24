// associated header
#include "generalmap.h"

// include
// std
#include <unordered_set>

// core
#include "gimpimage.h"
#include <QDebug>
namespace core
{


void fillRoom(const TilePos& pos, const Grid<Tile> tileGrid,
              Room& room,
              std::unordered_set<TilePos>& roomed,
              std::unordered_set<EdgePos>& walled)
{
  room.tiles.push_back(pos);
  roomed.insert(pos);

  auto add = [&](const TilePos& p)
  {
    if(tileGrid.inGrid(p.x, p.y))
    {
      if(tileGrid(p.x, p.y).texture == Tile::Texture::Floor &&
         roomed.find(p) == std::end(roomed))
      {
        fillRoom(p, tileGrid, room, roomed, walled);
      }
      else
      {
        EdgePos wall = {pos, p};
        if(tileGrid(p.x, p.y).texture != Tile::Texture::Floor &&
           walled.find(wall) == std::end(walled))
        {
          room.walls.push_back(wall);
          walled.insert(wall);
        }
      }
    }
  };

  add({pos.x + 1, pos.y});
  add({pos.x - 1, pos.y});
  add({pos.x, pos.y + 1});
  add({pos.x, pos.y - 1});
}


Room createRoom(const TilePos& pos, const Grid<Tile> tileGrid,
                std::unordered_set<TilePos>& roomed)
{
  std::unordered_set<EdgePos> walled;
  Room room;
  fillRoom(pos, tileGrid, room, roomed, walled);
  return std::move(room);
}


GeneralMap GeneralMap::fromGimpImage(const GimpImage& gImage)
{
  Grid<Tile> tileGrid(gImage.width(), gImage.height());
  std::vector<Obstacle> obstacles;
  std::vector<Door> doors;

  // initialize tile from image
  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      Tile::Type type = Tile::Type::None;
      Tile::Texture tex = Tile::Texture::None;
      const GimpColor& c = gImage(x, y);
      if(c == gimpGrass)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Grass;
      }
      else if(c == gimpFloor)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Floor;
      }
      else if(c == gimpRampart)
      {
        type = Tile::Type::Obstacle;
        tex = Tile::Texture::Rempart;
      }

      tileGrid(x, y) = Tile{type, tex};
    }
  }

  return std::move(GeneralMap(std::move(tileGrid), std::move(obstacles), std::move(doors)));
}


GeneralMap::GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
  std::vector<Door> doors)
  : _tileGrid(std::move(tiles))
  , _obstacles(std::move(obstacles))
  , _doors(std::move(doors))
{
  std::unordered_set<TilePos> roomedTile;
  for(std::size_t x = 0; x < _tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < _tileGrid.height(); ++y)
    {
      TilePos pos = {tile_index(x), tile_index(y)};
      if(_tileGrid(x, y).texture == Tile::Texture::Floor &&
         roomedTile.find(pos) == std::end(roomedTile))
      {
        _rooms.push_back(createRoom(pos, _tileGrid, roomedTile));
      }
    }
  }
}

} // core
