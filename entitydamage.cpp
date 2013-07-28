#include "entitydamage.h"

#include "gameworld.h"

EntityDamage::EntityDamage(size_t entityId, int healthPoint)
  :EntityModule(entityId)  , _healthPoint(healthPoint)
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

void EntityDamage::update()
{
  if(0 >= _healthPoint )
  {
    GameWorld::Instance().entityManager().deferredRemoveEntity(entityId());
  }
}
