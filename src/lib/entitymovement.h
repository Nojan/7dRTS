#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

#include "pch.h"

#include "entitymodule.h"

class MovememtTarget
{
public:
  enum State {
    Ordered,
    InProgress,
    Done,
    Abort,
  };
public:
  MovememtTarget(Eigen::Vector2f position);

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
  EntityMovement(size_t entityId);
  ~EntityMovement();

  Eigen::Vector2f position() const;
  void SetTarget(MovememtTarget * target);

  void update(float deltas);

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _speedMax;
  MovememtTarget * _target;
};

#endif // ENTITYMOVEMENT_H
