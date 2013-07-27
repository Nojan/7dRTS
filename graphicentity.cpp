#include "graphicentity.h"

#include "constantes.h"

using namespace core;

GraphicEntity::GraphicEntity()
  : _brush(Qt::black)
{
}

QRectF GraphicEntity::boundingRect() const
{
  return QRectF(0, 0, tileSize, tileSize);
}

QPainterPath GraphicEntity::shape() const
{
  QPainterPath path;
  path.addRect(boundingRect());
  return path;
}

void GraphicEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
  Q_UNUSED(option)
  Q_UNUSED(widget);
  painter->setBrush(_brush);
  painter->drawEllipse(0, 0, tileSize, tileSize);
}

void GraphicEntity::setPosition(float x, float y)
{
  _position = QPointF(x, y);
}

void GraphicEntity::setBrush(QBrush brush)
{
  _brush = brush;
}

void GraphicEntity::advance(int step)
{
  if(step<1)
    return;

  setPos(_position);
}
