#ifndef BALLISTICPROJECTILEMANAGER_H
#define BALLISTICPROJECTILEMANAGER_H
#include "pch.h"

#include "graphicentity.h"
#include "entityteam.h"

class GraphicBallisticProjectile : public GraphicEntity {
public:
  GraphicBallisticProjectile();

  virtual QRectF boundingRect() const;
  virtual QPainterPath shape() const;
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
};

namespace core {

class BallisticProjectile
{
public:
  BallisticProjectile(Eigen::Vector2f start, Eigen::Vector2f orientation, int damage);
  ~BallisticProjectile();

  Eigen::Vector2f position() const;
  Eigen::Vector2f orientation() const;
  int damage() const;
  float timeToLive() const;

  void setTeam(EntityTeam* team);
  EntityTeam * team();

  void evolve(float deltas);

  GraphicBallisticProjectile * graphic();

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _damage;
  float _timeToLive;
  GraphicBallisticProjectile _graphic;

  EntityTeam* _team;
};

class BallisticProjectileManager
{
public:
  BallisticProjectileManager();

  void addProjectile(BallisticProjectile* projectile, EntityTeam *team);

  void evolve(const float deltas);

private:
  std::vector<BallisticProjectile*> _projectiles;
  QGraphicsScene * _scene;
};

} //namespace core
#endif // BALLISTICPROJECTILEMANAGER_H
