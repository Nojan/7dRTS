#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

#include "pch.h"

#include "entitymodule.h"

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
  EntityMovement(size_t entityId, float speedMax);
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

#endif // ENTITYMOVEMENT_H
