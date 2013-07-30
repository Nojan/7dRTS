#include "entitymovement.h"

#include "constantes.h"
#include "entitymanager.h"
#include "entityposition.h"
#include "gameworld.h"


MovementTarget::MovementTarget(Eigen::Vector2f position)
  : _position(position)
  , _state(State::Ordered)
{
}

Eigen::Vector2f MovementTarget::position() const
{
  return _position;
}

MovementTarget::State MovementTarget::state() const
{
  return _state;
}

void MovementTarget::setState(MovementTarget::State state)
{
  _state = state;
}

EntityMovement::EntityMovement(size_t entityId, float speedMax)   // speedMax correspond au nombre de cases par secondes
  :EntityModule(entityId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  assert(entityManager.positionModule(entityId));
  _position = entityManager.positionModule(entityId)->position();
  _orientation = Eigen::Vector2f(1.f,0.f);
  _speedMax = speedMax * core::tileSizef;
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

void EntityMovement::setTarget(MovementTarget *target)
{
  if(NULL != _target)
    delete _target;

  _target = target;
  if(NULL != _target)
  {
    assert(MovementTarget::Ordered == _target->state());
    _target->setState(MovementTarget::InProgress);
  }
}

void EntityMovement::update(float deltas)
{
  assert(fabs(_orientation.dot(_orientation)-1.f)<0.1f); //check _orientation.IsNormalized(0.1f) ...
  if(_target && MovementTarget::InProgress == _target->state())
  {
    const Eigen::Vector2f targetDir = _target->position() - _position;
    _orientation = targetDir.normalized();
    _position += _orientation*_speedMax*deltas;
    if(targetDir.dot(_target->position() - _position) <= 0)
    {
      _position = _target->position();
      _target->setState(MovementTarget::Done);
    }
  }
}
