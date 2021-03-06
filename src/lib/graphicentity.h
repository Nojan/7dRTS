#ifndef GRAPHICENTITY_H
#define GRAPHICENTITY_H

// include
// Qt
#include <QGraphicsItem>
#include <QBrush>

namespace graphic
{

class GraphicEntity : public QGraphicsItem
{
public:
  GraphicEntity();

  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);

  void setEntityId(std::size_t entityId);
  std::size_t entityId() const;

  void setPosition(float x, float y);
  void setBrush(QBrush brush);

  void setHasHealthBar(bool hasHB);
  bool hasHealthBar();

  void setHealthPercentage(float healthPer);

protected:
  virtual void advance(int step);

protected:
  QBrush _brush;
  QPointF _position;
  bool _hasHealthBar;
  float _healthPercentage;
  std::size_t _entityId;
};

} // graphic

#endif // GRAPHICENTITY_H
