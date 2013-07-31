// associated header
#include "graphicdoor.h"

// include
// Qt
#include <QPainter>

namespace graphic
{

GraphicDoor::GraphicDoor(double length, double angle)
  : _doorRect(-length/2., -3., length, 6.)
{
  setRotation(angle);
}


QRectF GraphicDoor::boundingRect() const
{
  return _doorRect.adjusted(-1., -1., 1., 1.);
}


void GraphicDoor::paint(QPainter* painter,
                        const QStyleOptionGraphicsItem* /* option */ ,
                        QWidget* /* widget */)
{
  painter->setPen(QPen(Qt::black, 1.));
  painter->setBrush(QColor(0x78, 0x44, 0x21));
  painter->drawRect(_doorRect);
}

} // graphic
