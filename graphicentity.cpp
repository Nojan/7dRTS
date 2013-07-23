#include "graphicentity.h"

#include <QPainter>

GraphicEntity::GraphicEntity()
{
}

QRectF GraphicEntity::boundingRect() const
{
  return QRectF(-10, -10, 10, 10);
}

QPainterPath GraphicEntity::shape() const
{
  QPainterPath path;
  path.addRect(-10, -10, 10, 10);
  return path;
}

void GraphicEntity::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
  Q_UNUSED(option)
  Q_UNUSED(widget);
  painter->setBrush(Qt::red);
  painter->drawEllipse(-10, -10, 10, 10);
}

void GraphicEntity::setPosition(int x, int y)
{
  _position = QPointF(x, y);
}

void GraphicEntity::advance(int step)
{
  if(step<1)
    return;

  setPos(_position);
}
