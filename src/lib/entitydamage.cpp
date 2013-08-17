// associated header
#include "entitydamage.h"

// include
// core
#include "gameworld.h"


namespace core
{

EntityDamage::EntityDamage(std::size_t entityId, int healthPoint)
    :EntityModule(entityId)  , _healthPoint(healthPoint), _maxHealthPoint(healthPoint)
{

}

void EntityDamage::applyDamage(const int damagePoint)
{
  _healthPoint -= damagePoint;
}

int EntityDamage::healthPoint() const
{
  return _healthPoint;
}

int EntityDamage::maxHealthPoint() const
{
  return _maxHealthPoint;
}

void EntityDamage::update(const int deltaMs)
{
  if(0 >= _healthPoint )
  {
    GameWorld::Instance().entityManager().deferredRemoveEntity(entityId());
  }
}

} // core
