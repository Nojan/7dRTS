#include "entitymovement.h"

#include "entitymanager.h"
#include "entityposition.h"

EntityMovement::EntityMovement(size_t entityId)
  :EntityModule(entityId)
{
  assert(EntityManager::Instance().positionModule(entityId));
  _position = EntityManager::Instance().positionModule(entityId)->position();
  _orientation = Eigen::Vector2f(1.f,0.f);
  _speedMax = 10.f;
}

Eigen::Vector2f EntityMovement::position() const
{
  return _position;
}

void EntityMovement::update(float deltas)
{
  assert(fabs(_orientation.dot(_orientation)-1.f)<0.1f); //check _orientation.IsNormalized(0.1f) ...
  _position += _orientation*_speedMax*deltas;
}
