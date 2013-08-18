#ifndef BALLISTICPROJECTILEMANAGER_H
#define BALLISTICPROJECTILEMANAGER_H

// include
// pch
#include "pch.h"

// graphic
#include "graphicentity.h"

namespace core
{
  class EntityTeam;
}

namespace graphic
{

class GraphicBallisticProjectile : public GraphicEntity {
public:
  GraphicBallisticProjectile();

  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};

}

namespace core {

class BallisticProjectile
{
public:
  BallisticProjectile(const Eigen::Vector2f& start, const Eigen::Vector2f& orientation, int damage);
  ~BallisticProjectile();

  Eigen::Vector2f position() const;
  Eigen::Vector2f orientation() const;
  int damage() const;
  float timeToLive() const;

  void setTeam(EntityTeam* team);
  EntityTeam * team();

  void evolve(float deltas);

  graphic::GraphicBallisticProjectile * graphic();

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _damage;
  float _timeToLive;
  graphic::GraphicBallisticProjectile _graphic;

  EntityTeam* _team;
};

class BallisticProjectileManager
{
public:
  BallisticProjectileManager();
  ~BallisticProjectileManager();

  void clear();

  void addProjectile(BallisticProjectile* projectile);

  void evolve(const float deltas);

private:
  std::vector<BallisticProjectile*> _projectiles;
};

} // core

#endif // BALLISTICPROJECTILEMANAGER_H
