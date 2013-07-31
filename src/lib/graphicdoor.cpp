// associated header
#include "graphicdoor.h"

// include
// Qt
#include <QPainter>

static const double penSize = 1.;

namespace graphic
{

GraphicDoor::GraphicDoor(double length, double angle)
  : _doorRect(-length/2. - penSize, -3. - penSize,
              length + penSize, 6. + penSize)
  , _left(-length/2., -3., length/2., 6.)
  , _right(0., -3., length/2., 6.)
  , _percentOpen(0.)
{
  setRotation(angle);
}


float GraphicDoor::open() const
{
  return _percentOpen;
}


void GraphicDoor::open(float open)
{
  _percentOpen = open;
}


QRectF GraphicDoor::boundingRect() const
{
  return _doorRect;
}


void GraphicDoor::paint(QPainter* painter,
                        const QStyleOptionGraphicsItem* /* option */ ,
                        QWidget* /* widget */)
{
  painter->setPen(QPen(Qt::black, 1.));
  painter->setBrush(QColor(0x78, 0x44, 0x21));
  double adjust = _left.width()*_percentOpen;
  painter->drawRect(_left.adjusted(0., 0., -adjust, 0.));
  painter->drawRect(_right.adjusted(adjust, 0., 0., 0.));
}

} // graphic
