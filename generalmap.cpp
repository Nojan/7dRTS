// associated header
#include "generalmap.h"

// include
// std
#include <unordered_map>

// core
#include "gimpimage.h"

namespace core
{


GeneralMap GeneralMap::fromGimpImage(const GimpImage& gImage)
{
  Grid<Tile> tileGrid(gImage.width(), gImage.height());
  std::vector<Obstacle> obstacles;
  std::vector<Door> doors;

  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      Tile::Type type;
      Tile::Texture tex;
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

  return std::move(GeneralMap(std::move(tileGrid), std::move(obstacles), std::move(doors)));
}


GeneralMap::GeneralMap(Grid<Tile> tiles, std::vector<Obstacle> obstacles,
  std::vector<Door> doors)
  : _tileGrid(std::move(tiles))
  , _obstacles(std::move(obstacles))
  , _doors(std::move(doors))
{
}

} // core
