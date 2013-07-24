// associated header
#include "graphicmap.h"

// include
// Qt
#include <QImage>
#include <QPainter>

// core
#include <grid.h>
#include <generalmap.h>


/// @todo factorize with entity
static const QSize GridSize(32, 32);


QPoint toPixelPos(const core::TilePos& pos)
{
  return QPoint(pos.x*GridSize.width(), pos.y*GridSize.height());
}


namespace graphic
{

GraphicMap::GraphicMap(const core::GeneralMap* map, QGraphicsItem* parent)
  : QGraphicsPixmapItem(pixmapFromGeneralMap(map), parent)
{

}


void drawTile(QPainter& painter, QPoint pos, QColor tile)
{
  QRect rect(pos, GridSize);

  painter.save();

  painter.setBrush(QBrush(tile));
  painter.setPen(Qt::NoPen);
  painter.drawRect(rect);

  painter.setPen(QPen(QColor(0, 0, 0, 127), 1.));
  painter.drawLine(rect.topRight(), rect.bottomRight());
  painter.drawLine(rect.bottomLeft(), rect.bottomRight());

  painter.restore();
}


void drawVWall(QPainter& painter, QPoint begin, QPoint end)
{
  painter.save();
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(Qt::NoPen);
  QRect wall(begin + QPoint(-2, -2), end);
  painter.drawRect(wall);

  // draw shadow
  painter.setPen(QPen(QColor(0, 0, 0, 127), 1.));
  painter.drawLine(wall.topLeft() + QPoint(-1, 2), wall.bottomLeft() + QPoint(-1, -2));

  painter.restore();
}


void drawHWall(QPainter& painter, QPoint begin, QPoint end)
{
  painter.save();
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(Qt::NoPen);
  QRect wall(begin + QPoint(-2, -2), end);
  painter.drawRect(wall);

  // draw shadow
  painter.setPen(QPen(QColor(0, 0, 0, 127), 1.));
  painter.drawLine(wall.bottomLeft() + QPoint(2, 1), wall.bottomRight() + QPoint(-2, 1));

  painter.restore();
}


void drawGrass(QPainter& painter, QPoint pos)
{
  QColor grassColor(0x00, 0x80, 0x00);
  drawTile(painter, pos, grassColor);
}


void drawFloor(QPainter& painter, QPoint pos)
{
  QColor floorColor(0x99, 0x99, 0x99);
  drawTile(painter, pos, floorColor);
}


void drawRampart(QPainter& painter, QPoint pos)
{
  QColor wallColor(0x50, 0x2d, 0x16);
  drawTile(painter, pos, wallColor);
}


QPixmap GraphicMap::pixmapFromGeneralMap(const core::GeneralMap* map)
{
  const core::Grid<core::Tile>& tileGrid = map->tileGrid();
  QImage image(tileGrid.width()*(GridSize.width()),
               tileGrid.height()*(GridSize.height()), QImage::Format_ARGB32);
  QPainter painter(&image);

  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      QPoint pos(toPixelPos({core::tile_index(x), core::tile_index(y)}));
      if(tileGrid(x, y).texture == core::Tile::Texture::Grass)
      {
        drawGrass(painter, pos);
      }
      else if(tileGrid(x, y).texture == core::Tile::Texture::Floor)
      {
        drawFloor(painter, pos);
      }
      else if(tileGrid(x, y).texture == core::Tile::Texture::Rampart)
      {
        drawRampart(painter, pos);
      }
    }
  }


  for(const core::Room& room: map->rooms())
  {
    for(const core::EdgePos& ep: room.walls)
    {
      if(ep.from.x > ep.to.x)
      {
        QPoint begin(toPixelPos(ep.from));
        QPoint end(begin + QPoint(0, GridSize.height()));
        drawVWall(painter, begin, end);
      }
      if(ep.from.x < ep.to.x)
      {
        QPoint begin(toPixelPos(ep.to));
        QPoint end(begin + QPoint(0, GridSize.height()));
        drawVWall(painter, begin, end);
      }
      if(ep.from.y > ep.to.y)
      {
        QPoint begin(toPixelPos(ep.from));
        QPoint end(begin + QPoint(GridSize.width(), 0));
        drawHWall(painter, begin, end);
      }
      if(ep.from.y < ep.to.y)
      {
        QPoint begin(toPixelPos(ep.to));
        QPoint end(begin + QPoint(GridSize.width(), 0));
        drawHWall(painter, begin, end);
      }
    }
  }


  return QPixmap::fromImage(image);
}

} // graphic

