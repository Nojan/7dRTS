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


void drawWall(QPainter& painter, QPoint pos)
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
      QPoint pos(x*GridSize.width(), y*GridSize.height());
      if(tileGrid(x, y).texture == core::Tile::Texture::Grass)
      {
        drawGrass(painter, pos);
      }
      else if(tileGrid(x, y).texture == core::Tile::Texture::Floor)
      {
        drawFloor(painter, pos);
      }
      else if(tileGrid(x, y).texture == core::Tile::Texture::Wall)
      {
        drawWall(painter, pos);
      }
    }
  }


  return QPixmap::fromImage(image);
}

} // graphic

