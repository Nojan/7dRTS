#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

#include <QGraphicsItem>

#include <QBrush>

class GraphicEntity : public QGraphicsItem
{
public:
  GraphicEntity();

  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  void setPosition(float x, float y);
  void setBrush(QBrush brush);

protected:
  virtual void advance(int step);

protected:
  QBrush _brush;
  QPointF _position;
};

#endif // GRAPHICENTITY_H
