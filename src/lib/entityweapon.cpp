// associated header
#include "entityweapon.h"

// include
// core
#include "ballisticprojectilemanager.h"
#include "constantes.h"
#include "entitydamage.h"
#include "entitymanager.h"
#include "entityposition.h"
#include "gameworld.h"

namespace core
{

WeaponTarget::WeaponTarget(std::size_t entityId)
  : _target(entityId)
{
}

size_t WeaponTarget::targetId() const
{
  return _target;
}
EntityWeapon::EntityWeapon(std::size_t entityId, int damage, float range, int fireRate)

  : EntityModule(entityId)
  , _damagePower(damage)
  , _range(range * core::tileSizef)
  , _fireRate(fireRate)
  , _fireRateCurrent(0)
  , _target(NULL)
{
}

void EntityWeapon::update(int deltaMs)
{
  if(0 < _fireRateCurrent)
    _fireRateCurrent -= deltaMs;
  if(0 >= _fireRateCurrent)
  {
    EntityManager& entityManager = GameWorld::Instance().entityManager();
    _fireRateCurrent = 0;
    if(_target)
    {
      const Eigen::Vector2f targetPosition = entityManager.positionModule(_target->targetId())->position();
      if(canShootAt(targetPosition))
        shootAt(targetPosition);
    }
  }
}

void EntityWeapon::setTarget(WeaponTarget *target)
{
  if(NULL != _target)
    delete _target;
  _target = target;
}

bool EntityWeapon::canShootAt(const Eigen::Vector2f& position) const
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const Eigen::Vector2f selfPosition = entityManager.positionModule(entityId())->position();
  return (selfPosition - position).norm() <= float(_range);
}

void EntityWeapon::shootAt(const Eigen::Vector2f& position)
{
  assert(canShootAt(position));
  _fireRateCurrent = _fireRate;
  // emit bullet or something
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const Eigen::Vector2f selfPosition = entityManager.positionModule(entityId())->position();
  const Eigen::Vector2f projectileOrientation = (position - selfPosition).normalized();
  core::BallisticProjectile * projectile = new core::BallisticProjectile(selfPosition + projectileOrientation*32.f, projectileOrientation, 5);
  GameWorld::Instance().ballisticProjectileManager().addProjectile(projectile, entityManager.teamModule(entityId()));
}

} // core
