// associated header
#include "maptypes.h"

// include
// std
#include <algorithm>

// core
#include "constantes.h"

namespace core
{


/*
 *               pixel calculator
 */


Eigen::Vector2i pixelTopLeft(const TilePos& pos)
{
  return Eigen::Vector2i(pos)*core::tileSize;
}


Eigen::Vector2i pixelTopLeft(const EdgePos& edge)
{
  Eigen::Vector2i dir = edge.direction();
  Eigen::Vector2i off(-std::abs(dir.y()), -std::abs(dir.x()));
  return pixelCenter(edge) + off;
}


Eigen::Vector2i pixelCenter(const TilePos& pos)
{
  return Eigen::Vector2i(pos)*core::tileSize +
      Eigen::Vector2i(core::tileHalfSize, core::tileHalfSize);
}


Eigen::Vector2i pixelCenter(const EdgePos& edge)
{
  return (pixelCenter(edge.from) + pixelCenter(edge.to))/2;
}


TilePos tileFromPixel(const Eigen::Vector2i& pix)
{
  return TilePos{pix/core::tileSize};
}


/*
 *                  Door
 */


Door::Door()
  : _edges()
{ }


Door::Door(std::vector<EdgePos> edges)
  : _edges(std::move(edges))
{
  sort();
}


Door& Door::operator=(std::vector<EdgePos> edges)
{
  _edges = std::move(edges);
  sort();
  return *this;
}


Eigen::Vector2i Door::center() const
{
  return (pixelCenter(_edges.front()) + pixelCenter(_edges.back()))/2;
}


void Door::sort()
{
  std::sort(_edges.begin(), _edges.end());
}


} // core
