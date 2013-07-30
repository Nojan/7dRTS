// associated header
#include "graphicpathfindingmap.h"

// include
// Qt
#include <QImage>
#include <QPainter>

// core
#include <pathfindingmap.h>


/// @todo factorize with entity
static const QSize GridSize(32, 32);


namespace graphic
{

GraphicPathFindingMap::GraphicPathFindingMap(const core::PathFindingMap* map,
                                             QGraphicsItem* parent)
  : QGraphicsPixmapItem(pixmapFromPathFindingMap(map), parent)
{
}


QPoint tileCenter(core::tile_index x, core::tile_index y)
{
  return QPoint(x*GridSize.width() + GridSize.width()/2,
                y*GridSize.height() + GridSize.height()/2);
}


QPixmap GraphicPathFindingMap::pixmapFromPathFindingMap(
    const core::PathFindingMap* map)
{
  QImage image(map->width()*GridSize.width(),
               map->height()*GridSize.height(), QImage::Format_ARGB32);
  QPainter painter(&image);

  for(std::size_t x = 0; x < map->width(); ++x)
  {
    for(std::size_t y = 0; y < map->height(); ++y)
    {
      QPoint origin = tileCenter(x, y);
      core::TilePos tile{core::tile_index(x), core::tile_index(y)};
      for(const core::TilePos& pos: map->neighbor(tile))
      {
        QPoint dest = tileCenter(pos.x, pos.y);
        painter.drawLine(origin, dest);
      }
    }
  }

  return QPixmap::fromImage(image);
}

} // graphic
