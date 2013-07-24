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


bool isValidRoom(const TilePos& pos, const Grid<Tile>& tileGrid,
                 std::unordered_set<TilePos>& roomed)
{
  return tileGrid.inGrid(pos.x, pos.y) &&
         tileGrid(pos.x, pos.y).texture == Tile::Texture::Floor &&
         roomed.find(pos) == std::end(roomed);
}


void addRoomTile(const TilePos& pos, const Grid<Tile> tileGrid,
                 std::vector<TilePos>& tiles,
                 std::unordered_set<TilePos>& roomed)
{
  tiles.push_back(pos);
  roomed.insert(pos);
  if(isValidRoom({pos.x + 1, pos.y}, tileGrid, roomed))
  {
    addRoomTile({pos.x + 1, pos.y}, tileGrid, tiles, roomed);
  }
  if(isValidRoom({pos.x - 1, pos.y}, tileGrid, roomed))
  {
    addRoomTile({pos.x - 1, pos.y}, tileGrid, tiles, roomed);
  }
  if(isValidRoom({pos.x, pos.y + 1}, tileGrid, roomed))
  {
    addRoomTile({pos.x, pos.y + 1}, tileGrid, tiles, roomed);
  }
  if(isValidRoom({pos.x, pos.y - 1}, tileGrid, roomed))
  {
    addRoomTile({pos.x, pos.y - 1}, tileGrid, tiles, roomed);
  }
}


Room createRoom(const TilePos& pos, const Grid<Tile> tileGrid,
                std::unordered_set<TilePos>& roomed)
{
  Room room;
  addRoomTile(pos, tileGrid, room.tiles, roomed);
  return std::move(room);
}


GeneralMap GeneralMap::fromGimpImage(const GimpImage& gImage)
{
  Grid<Tile> tileGrid(gImage.width(), gImage.height());
  std::vector<Obstacle> obstacles;
  std::vector<Door> doors;
  std::vector<Room> rooms;

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
      else if(c == gimpWall)
      {
        type = Tile::Type::Obstacle;
        tex = Tile::Texture::Wall;
      }

      tileGrid(x, y) = Tile{type, tex};
    }
  }


  std::unordered_set<TilePos> roomedTile;
  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      TilePos pos = {tile_index(x), tile_index(y)};
      if(tileGrid(x, y).texture == Tile::Texture::Floor &&
         roomedTile.find(pos) == std::end(roomedTile))
      {
        rooms.push_back(createRoom(pos, tileGrid, roomedTile));
      }
    }
  }

  return std::move(GeneralMap(std::move(tileGrid), std::move(obstacles), std::move(doors),
                   std::move(rooms)));
}


GeneralMap::GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
  std::vector<Door> doors, std::vector<Room> rooms)
  : _tileGrid(std::move(tiles))
  , _obstacles(std::move(obstacles))
  , _doors(std::move(doors))
  , _rooms(std::move(rooms))
{
}

} // core
