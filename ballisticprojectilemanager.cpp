#include "ballisticprojectilemanager.h"

#include "constantes.h"
#include "gameworld.h"

GraphicBallisticProjectile::GraphicBallisticProjectile()
{
}

QRectF GraphicBallisticProjectile::boundingRect() const
{
  return QRectF(0.f, 0.f, core::tileSizef*0.2f, core::tileSizef*0.2f);
}

QPainterPath GraphicBallisticProjectile::shape() const
{
  QPainterPath path;
  path.addRect(boundingRect());
  return path;
}

void GraphicBallisticProjectile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
           QWidget *widget)
{
  Q_UNUSED(option)
  Q_UNUSED(widget);
  painter->setBrush(Qt::yellow);
  painter->drawRect(boundingRect());
}

using namespace core;

BallisticProjectile::BallisticProjectile(Eigen::Vector2f start, Eigen::Vector2f orientation, int damage)
  : _position(start)
  , _orientation(orientation)
  , _damage(damage)
  , _timeToLive(10)
  , _graphic()
{
}

BallisticProjectile::~BallisticProjectile()
{
  if(_graphic.scene())
    _graphic.scene()->removeItem(&_graphic);
}

Eigen::Vector2f BallisticProjectile::position() const
{
  return _position;
}

Eigen::Vector2f BallisticProjectile::orientation() const
{
  return _orientation;
}

int BallisticProjectile::damage() const
{
  return _damage;
}

float BallisticProjectile::timeToLive() const
{
  return _timeToLive;
}

void BallisticProjectile::evolve(float deltas)
{
  _timeToLive -= deltas;
  _position += _orientation*core::tileSizef*6.f*deltas;
  _graphic.setPosition(_position.x(), _position.y());
}

GraphicBallisticProjectile *BallisticProjectile::graphic()
{
  return &_graphic;
}

BallisticProjectileManager::BallisticProjectileManager()
{
}

void BallisticProjectileManager::addProjectile(BallisticProjectile *projectile)
{
  GameWorld::Instance().scene()->addItem(projectile->graphic());
  BallisticProjectile* p;
  for(size_t i =0; i< _projectiles.size(); ++i)
  {
    p=_projectiles.at(i);
    if(NULL == p)
    {
      p = projectile;
      return;
    }
  }
  _projectiles.push_back(projectile);
}

void BallisticProjectileManager::evolve(const float deltas)
{
  BallisticProjectile* projectile;
  for(size_t i =0; i< _projectiles.size(); ++i)
  {
    projectile = _projectiles.at(i);
    if(projectile)
    {
      projectile->evolve(deltas);
      if(projectile->timeToLive() < 0.f)
      {
        _projectiles[i] = NULL;
        delete projectile;
      }
    }
  }
}

