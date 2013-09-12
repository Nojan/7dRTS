// associated header
#include "generalmap.h"

// include
// std
#include <unordered_set>

// core
#include "gimpimage.h"

namespace core
{

/*
 *                 GeneralMap
 */



template<typename T, typename Func>
void applyOnNeigbor(const Grid<T>& grid, int x, int y, Func& func)
{
  if(grid.inGrid(x + 1, y))
  {
    func(x + 1, y);
  }
  if(grid.inGrid(x - 1, y))
  {
    func(x - 1, y);
  }
  if(grid.inGrid(x, y + 1))
  {
    func(x, y + 1);
  }
  if(grid.inGrid(x, y - 1))
  {
    func(x, y - 1);
  }
}


void fillFromTexture(const TilePos& pos, const Grid<Tile>& tileGrid,
                     Tile::Texture texture,
                     std::vector<TilePos>& tiles,
                     std::vector<EdgePos>& walls,
                     std::unordered_set<TilePos>& tiled,
                     std::unordered_set<EdgePos>& walled)
{
  tiles.push_back(pos);
  tiled.insert(pos);

  auto add = [&](const TilePos& p)
  {
    if(tileGrid.inGrid(p.x, p.y))
    {
      if(tileGrid.at(p.x, p.y).texture == texture &&
         tiled.find(p) == std::end(tiled))
      {
        fillFromTexture(p, tileGrid, texture, tiles, walls, tiled, walled);
      }
      else
      {
        EdgePos wall = {pos, p};
        if(tileGrid.at(p.x, p.y).texture != texture &&
           walled.find(wall) == std::end(walled))
        {
          walls.push_back(wall);
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


void addEntranceAdj(const TilePos& pos, const Grid<GimpColor>& colors,
                    GimpColor insideColor, GimpColor outsideColor,
                    std::vector<EdgePos>& entrance,
                    std::unordered_set<TilePos>& tiled)
{
  tiled.insert(pos);

  auto add = [&](const TilePos& adj)
  {
    if(colors.inGrid(adj.x, adj.y))
    {
      if(colors.at(adj.x, adj.y) == outsideColor)
      {
        entrance.push_back({pos, adj});
      }
      else if(colors.at(adj.x, adj.y) == insideColor &&
              tiled.find(adj) == std::end(tiled))
      {
        addEntranceAdj(adj, colors, insideColor, outsideColor, entrance, tiled);
      }
    }
  };

  add({pos.x + 1, pos.y});
  add({pos.x - 1, pos.y});
  add({pos.x, pos.y + 1});
  add({pos.x, pos.y - 1});
}


std::vector<std::vector<EdgePos> >
findEntrance(const std::vector<TilePos>& tiles,
             const Grid<GimpColor>& colors,
             GimpColor insideColor,
             GimpColor outsideColor)
{
  std::vector<std::vector<EdgePos> > entrances;
  std::unordered_set<TilePos> tiled;

  for(const TilePos& pos: tiles)
  {
    if((colors.at(pos.x, pos.y) == insideColor) &&
       (tiled.find(pos) == std::end(tiled)))
    {
      std::vector<EdgePos> entrance;
      addEntranceAdj(pos, colors, insideColor, outsideColor, entrance, tiled);
      entrances.push_back(entrance);
    }
  }

  return entrances;
}


Room createRoom(const TilePos& pos, const Grid<Tile>& tileGrid,
                std::unordered_set<TilePos>& roomed)
{
  std::unordered_set<EdgePos> walled;
  Room room;
  fillFromTexture(pos, tileGrid, Tile::Texture::Floor, room.tiles, room.walls, roomed, walled);
  return std::move(room);
}


Rampart createRampart(const TilePos& pos, const Grid<Tile>& tileGrid)
{
  std::unordered_set<TilePos> rampared;
  std::unordered_set<EdgePos> walled;
  Rampart ramp;
  fillFromTexture(pos, tileGrid, Tile::Texture::Rampart, ramp.tiles, ramp.walls,
                  rampared, walled);
  return std::move(ramp);
}


GeneralMap GeneralMap::fromGimpImage(const GimpImage& gImage)
{
  Grid<Tile> tileGrid(gImage.width(), gImage.height());
  std::vector<Obstacle> obstacles;
  std::vector<Room> rooms;

  std::vector<EdgePos> rampartDoors;
  Rampart rampart;

  // initialize tile from image
  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      Tile::Type type = Tile::Type::None;
      Tile::Texture tex = Tile::Texture::None;
      const GimpColor& c = gImage.at(x, y);
      TilePos pos{tile_index(x), tile_index(y)};
      if(c == gimpGrass || c == gimpGrassEntrance)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Grass;
      }
      else if(c == gimpFloor || c == gimpFloorEntrance)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Floor;
      }
      else if(c == gimpRampart)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Rampart;
        rampart.tiles.push_back(pos);

        auto findWall = [&gImage, &rampart, &pos](int xc, int yc)
        {
          const GimpColor& c = gImage.at(xc, yc);
          if(!(c == gimpRampart || c == gimpRampartEntrance))
          {
            rampart.walls.push_back({pos, {xc, yc}});
          }
        };
        applyOnNeigbor(gImage, x, y, findWall);
      }
      else if(c == gimpRampartEntrance)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Rampart;
        rampart.tiles.push_back(pos);

        auto findWall = [&gImage, &rampart, &pos](int xc, int yc)
        {
          const GimpColor& c = gImage.at(xc, yc);
          if(!(c == gimpRampart || c == gimpRampartEntrance ||
               c == gimpGrassEntrance))
          {
            rampart.walls.push_back({pos, {xc, yc}});
          }
        };
        applyOnNeigbor(gImage, x, y, findWall);
      }
      else if(c == gimpPath || c == gimpPathEntrance)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Path;
      }
      else if(c == gimpRampartDoor)
      {
        type = Tile::Type::Free;
        tex = Tile::Texture::Grass;

        auto findEntrance = [&gImage, &rampartDoors, &pos](int xc, int yc)
        {
          const GimpColor& c = gImage.at(xc, yc);
          if(c == gimpPathEntrance || c == gimpGrassEntrance)
          {
            rampartDoors.push_back({pos, {xc, yc}});
          }
        };
        applyOnNeigbor(gImage, x, y, findEntrance);
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
        Room room = createRoom(pos, tileGrid, roomedTile);
        for(const std::vector<EdgePos>& entrance:
            findEntrance(room.tiles, gImage,
                         gimpFloorEntrance,
                         gimpGrassEntrance))
        {
          room.doors.push_back({entrance});
          for(const EdgePos& edge: entrance)
          {
            room.walls.erase(
                  std::find(std::begin(room.walls),
                            std::end(room.walls), edge));
          }
        }
        rooms.push_back(room);
      }
    }
  }

  // find all adjacent rampart door edge to make rampart doors
  while(!rampartDoors.empty())
  {
    std::vector<EdgePos> edges = {rampartDoors.back()};
    rampartDoors.pop_back();
    bool found = true;
    while(found)
    {
      found = false;
      for(const EdgePos& e1: edges)
      {
        rampartDoors.erase(std::remove_if(rampartDoors.begin(), rampartDoors.end(),
                                          [&e1, &edges, &found](const EdgePos& e2)
        {
          if(e1.from.manhattan(e2.from) == 1)
          {
            found = true;
            edges.push_back(e2);
            return true;
          }
          return false;
        }), rampartDoors.end());
      }
    }
    rampart.doors.push_back({edges});
  }

  return GeneralMap(std::move(tileGrid), std::move(obstacles),
                    std::move(rooms), std::move(rampart));
}


GeneralMap::GeneralMap()
{ }


GeneralMap::GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
  std::vector<Room> rooms, Rampart rampart)
  : _tileGrid(std::move(tiles))
  , _obstacles(std::move(obstacles))
  , _rooms(std::move(rooms))
  , _rampart(std::move(rampart))
{
}

} // core
