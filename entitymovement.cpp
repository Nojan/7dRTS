#include "entitymovement.h"

#include "constantes.h"
#include "entitymanager.h"
#include "entityposition.h"


MovememtTarget::MovememtTarget(Eigen::Vector2f position)
  : _position(position)
  , _state(State::Ordered)
{
}

Eigen::Vector2f MovememtTarget::position() const
{
  return _position;
}

MovememtTarget::State MovememtTarget::state() const
{
  return _state;
}

void MovememtTarget::setState(MovememtTarget::State state)
{
  _state = state;
}

EntityMovement::EntityMovement(size_t entityId)
  :EntityModule(entityId)
{
  assert(EntityManager::Instance().positionModule(entityId));
  _position = EntityManager::Instance().positionModule(entityId)->position();
  _orientation = Eigen::Vector2f(1.f,0.f);
  _speedMax = core::tileSizef;
  _target = NULL;
}

EntityMovement::~EntityMovement()
{
  if(_target)
    delete _target;
}

Eigen::Vector2f EntityMovement::position() const
{
  return _position;
}

void EntityMovement::SetTarget(MovememtTarget *target)
{
  if(NULL != _target)
    delete _target;
  _target = target;
  if(NULL != _target)
  {
    assert(MovememtTarget::Ordered == _target->state());
    _target->setState(MovememtTarget::InProgress);
  }
}

void EntityMovement::update(float deltas)
{
  assert(fabs(_orientation.dot(_orientation)-1.f)<0.1f); //check _orientation.IsNormalized(0.1f) ...
  if(_target && MovememtTarget::InProgress == _target->state())
  {
    const Eigen::Vector2f targetDir = _target->position() - _position;
    _orientation = targetDir.normalized();
    _position += _orientation*_speedMax*deltas;
    if(targetDir.dot(_target->position() - _position) <= 0)
    {
      _position = _target->position();
      _target->setState(MovememtTarget::Done);
    }
  }
}
