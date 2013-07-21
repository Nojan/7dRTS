#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

#include <QGraphicsItem>

class GraphicEntity : public QGraphicsItem
{
public:
  GraphicEntity();

  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  void setPosition(int x, int y);

protected:
  virtual void advance(int step);

private:
  QPointF _position;
};

#endif // GRAPHICENTITY_H
