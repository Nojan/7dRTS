// associated header
#include "graphicentity.h"

// include
// pch
#include "pch.h"

// Qt
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

// core
#include "constantes.h"

using namespace core;

namespace graphic
{

GraphicEntity::GraphicEntity()
    : _brush(Qt::black)
    , _hasHealthBar(false)
    , _healthPercentage(1.0f)
    , _entityId(std::numeric_limits<std::size_t>::max())
{
  setFlag(QGraphicsItem::ItemIsSelectable);
}

QRectF GraphicEntity::boundingRect() const
{
  return QRectF(-tileHalfSize, -tileHalfSize-6, tileSize, tileSize+6);
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
  painter->drawEllipse(-tileHalfSize, -tileHalfSize, tileSize, tileSize);
  if(_hasHealthBar)
  {
      painter->setBrush(Qt::black);
      painter->drawRect(-tileHalfSize, -tileHalfSize-6, tileSize, 4);

      if(_healthPercentage > 0.75f)
          painter->setBrush(Qt::green);
      else if(_healthPercentage > 0.25f)
          painter->setBrush(Qt::yellow);
      else
          painter->setBrush(Qt::red);
      painter->drawRect(-tileHalfSize, -tileHalfSize-6, tileSize * _healthPercentage, 4);
  }
}


void GraphicEntity::setEntityId(std::size_t entityId)
{
  _entityId = entityId;
}


std::size_t GraphicEntity::entityId() const
{
  return _entityId;
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


void GraphicEntity::setHasHealthBar(bool hasHB)
{
    _hasHealthBar = hasHB;
}

bool GraphicEntity::hasHealthBar()
{
    return _hasHealthBar;
}

void GraphicEntity::setHealthPercentage(float healthPer)
{
    if(healthPer != _healthPercentage)
    {
        _healthPercentage = healthPer;
        update();
    }
}

}
