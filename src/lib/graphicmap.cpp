// associated header
#include "graphicmap.h"

// include
// Qt
#include <QImage>
#include <QPainter>

// core
#include <constantes.h>
#include <grid.h>
#include <generalmap.h>


static const QSize GridSize(core::tileSize, core::tileSize);


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


void drawVWall(QPainter& painter, QPoint begin, QPoint end, int size)
{
  painter.save();
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(Qt::NoPen);
  QRect wall(begin + QPoint(-size + 1, -size + 1), end);
  painter.drawRect(wall);

  // draw shadow
  painter.setPen(QPen(QColor(0, 0, 0, 127), 1.));
  painter.drawLine(wall.topLeft() + QPoint(-1, 2), wall.bottomLeft() + QPoint(-1, -2));

  painter.restore();
}


void drawHWall(QPainter& painter, QPoint begin, QPoint end, int size)
{
  painter.save();
  painter.setBrush(QBrush(Qt::black));
  painter.setPen(Qt::NoPen);
  QRect wall(begin + QPoint(-size + 1, -size + 1), end);
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


void drawPath(QPainter& painter, QPoint pos)
{
  QColor pathColor(0xc8, 0x71, 0x37);
  drawTile(painter, pos, pathColor);
}


void drawWall(QPainter& painter, const std::vector<core::EdgePos>& walls,
              int size)
{
  for(const core::EdgePos& ep: walls)
  {
    if(ep.from.x > ep.to.x)
    {
      QPoint begin(toPixelPos(ep.from));
      QPoint end(begin + QPoint(0, GridSize.height()));
      drawVWall(painter, begin, end, size);
    }
    if(ep.from.x < ep.to.x)
    {
      QPoint begin(toPixelPos(ep.to));
      QPoint end(begin + QPoint(0, GridSize.height()));
      drawVWall(painter, begin, end, size);
    }
    if(ep.from.y > ep.to.y)
    {
      QPoint begin(toPixelPos(ep.from));
      QPoint end(begin + QPoint(GridSize.width(), 0));
      drawHWall(painter, begin, end, size);
    }
    if(ep.from.y < ep.to.y)
    {
      QPoint begin(toPixelPos(ep.to));
      QPoint end(begin + QPoint(GridSize.width(), 0));
      drawHWall(painter, begin, end, size);
    }
  }
}


QPixmap GraphicMap::pixmapFromGeneralMap(const core::GeneralMap* map)
{
  const core::Grid<core::Tile>& tileGrid = map->tileGrid();
  QImage image(tileGrid.width()*(GridSize.width()),
               tileGrid.height()*(GridSize.height()), QImage::Format_ARGB32);
  image.fill(Qt::white);
  QPainter painter(&image);

  for(std::size_t x = 0; x < tileGrid.width(); ++x)
  {
    for(std::size_t y = 0; y < tileGrid.height(); ++y)
    {
      QPoint pos(toPixelPos({core::tile_index(x), core::tile_index(y)}));
      if(tileGrid.at(x, y).texture == core::Tile::Texture::Grass)
      {
        drawGrass(painter, pos);
      }
      else if(tileGrid.at(x, y).texture == core::Tile::Texture::Floor)
      {
        drawFloor(painter, pos);
      }
      else if(tileGrid.at(x, y).texture == core::Tile::Texture::Rampart)
      {
        drawRampart(painter, pos);
      }
      else if(tileGrid.at(x, y).texture == core::Tile::Texture::Path)
      {
        drawPath(painter, pos);
      }
    }
  }


  for(const core::Room& room: map->rooms())
  {
    drawWall(painter, room.walls, 3);
  }

  drawWall(painter, map->rampart().walls, 5);

  return QPixmap::fromImage(image);
}

} // graphic

