#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"


namespace core
{

class MovementTarget
{
public:
  enum State {
    Ordered,
    InProgress,
    Done,
    Abort,
  };
public:
  MovementTarget(const Eigen::Vector2f& position);

  Eigen::Vector2f position() const;
  State state() const;
  void setState(State state);

private:
  Eigen::Vector2f _position;
  State _state;
};

class EntityMovement : public EntityModule
{
public:
  EntityMovement(std::size_t entityId, float speedMax);
  virtual ~EntityMovement();

  Eigen::Vector2f position() const;
  void setTarget(MovementTarget * target);

  void update(float deltas);

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _speedMax;    // nb pixels par seconde
  MovementTarget * _target;
};

} // core

#endif // ENTITYMOVEMENT_H
