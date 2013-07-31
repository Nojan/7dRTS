#include "ballisticprojectilemanager.h"

#include "constantes.h"
#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entityposition.h"
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
//  for(size_t i =0; i< _projectiles.size(); ++i)
//  {
//    p=_projectiles.at(i);
//    if(NULL == p)
//    {
//      p = projectile;
//      return;
//    }
//  }
  _projectiles.push_back(projectile);
}

static bool collideGraphics(BallisticProjectile& projectile, const size_t entity)
{
  EntityGraphicHolder* graphicHolder = GameWorld::Instance().entityManager().GraphicHolderModule(entity);
  if(!graphicHolder)
    return false;
  return projectile.graphic()->collidesWithItem(graphicHolder->graphic());
}

static bool collide(BallisticProjectile& projectile, const size_t entity)
{
  EntityPosition* positionModule = GameWorld::Instance().entityManager().positionModule(entity);
  if(!positionModule)
    return false;
  return (positionModule->position() - projectile.position()).norm() < positionModule->size();
}

void BallisticProjectileManager::evolve(const float deltas)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityCount = entityManager.entityCount();
  BallisticProjectile* projectile;
  bool collided = false;
  for(size_t i =0; i< _projectiles.size(); ++i)
  {
    projectile = _projectiles.at(i);
    if(projectile)
    {
      projectile->evolve(deltas);
      for(size_t entityId = 0; entityId<entityCount; ++entityId)
      {
        collided = collide(*projectile, entityId);
        if(collided)
          entityManager.damageModule(entityId)->applyDamage(projectile->damage());
      }
      if(collided || projectile->timeToLive() < 0.f)
      {
        _projectiles[i] = NULL;
        delete projectile;
      }
    }
    collided = false;
  }
}
