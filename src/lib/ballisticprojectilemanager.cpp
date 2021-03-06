// associtaed header
#include "ballisticprojectilemanager.h"

// include
// core
#include "constantes.h"
#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entityposition.h"
#include "entityteam.h"
#include "gameworld.h"

namespace graphic
{

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

} // graphic


namespace core
{

BallisticProjectile::BallisticProjectile(const Eigen::Vector2f& start, const Eigen::Vector2f& orientation, int damage)
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


void BallisticProjectile::setTeam(EntityTeam* team)
{
  _team = team;
}

EntityTeam * BallisticProjectile::team()
{
    return _team;
}

void BallisticProjectile::evolve(float deltas)
{
  _timeToLive -= deltas;
  _position += _orientation*core::tileSizef*6.f*deltas;
  _graphic.setPosition(_position.x(), _position.y());
}

graphic::GraphicBallisticProjectile *BallisticProjectile::graphic()
{
  return &_graphic;
}

BallisticProjectileManager::BallisticProjectileManager()
{
}

BallisticProjectileManager::~BallisticProjectileManager()
{
  clear();
}

void BallisticProjectileManager::clear()
{
  for(BallisticProjectile *projectile : _projectiles)
  {
    if(projectile)
      delete projectile;
  }
  _projectiles.clear();
}

void BallisticProjectileManager::addProjectile(BallisticProjectile *projectile)
{
  GameWorld::Instance().scene()->addItem(projectile->graphic());
  for(std::size_t i =0; i< _projectiles.size(); ++i)
  {
    if(_projectiles.at(i) == NULL)
    {
      _projectiles[i] = projectile;
      return;
    }
  }
  _projectiles.push_back(projectile);
}


static bool collideGraphics(BallisticProjectile& projectile, const size_t entity)
{
  EntityGraphicHolder* graphicHolder = GameWorld::Instance().entityManager().GraphicHolderModule(entity);
  if(!graphicHolder)
    return false;
  return projectile.graphic()->collidesWithItem(graphicHolder->graphic());
}

void BallisticProjectileManager::evolve(const float deltas)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityCount = entityManager.entityCount();
  BallisticProjectile* projectile;
  bool collided = false;
  for(std::size_t i =0; i< _projectiles.size(); ++i)
  {
    projectile = _projectiles.at(i);
    if(projectile)
    {
      projectile->evolve(deltas);
      for(std::size_t entityId = 0; entityId<entityCount; ++entityId)
      {

        collided = collideGraphics(*projectile, entityId);
        if(collided)
        {
            if(projectile->team()->team() != entityManager.teamModule(entityId)->team())
            {
                entityManager.damageModule(entityId)->applyDamage(projectile->damage());
                _projectiles[i] = NULL;
                delete projectile;
                break;
            }

        }

      }

      if(!collided)
      {
          if(projectile->timeToLive() < 0.f)
          {
              _projectiles[i] = NULL;
              delete projectile;
              break;
          }

      }

      collided = false;
    }


  }
}

} // core

