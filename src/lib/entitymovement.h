#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

// include
// pch
#include "pch.h"

// Eigen
#include <unsupported/Splines>

// core
#include "entitymodule.h"
#include "maptypes.h"


namespace core
{

class MovementTarget
{
public:
  enum State {
    Ordered,
    InProgress,
    Done,
    Abort
  };
public:
  MovementTarget(const Eigen::Vector2f& start, const Eigen::Vector2f& target);

  Eigen::Vector2f position(float t) const;
  float duration() const;

  State state() const;
  void setState(State state);

private:
  std::vector<TilePos> _path;
  Eigen::Spline<float, 2, 1> _splinePath;
  float _duration;
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
  float _time;
  MovementTarget * _target;
};

} // core

#endif // ENTITYMOVEMENT_H
