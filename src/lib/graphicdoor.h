#ifndef GRAPHICDOOR_H
#define GRAPHICDOOR_H

// include
// graphic
#include "graphicentity.h"

namespace graphic
{

class GraphicDoor : public GraphicEntity
{
public:
  GraphicDoor(double length, double angle);

  float open() const;
  void open(float open);

  virtual QRectF boundingRect() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                     QWidget *widget);

private:
  QRectF _doorRect;
  QRectF _left, _right;
  float _percentOpen;
};

} // graphic

#endif // GRAPHICDOOR_H
