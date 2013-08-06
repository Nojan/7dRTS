#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

// include
// pch
#include "pch.h"

// std
#include <memory>

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
  MovementTarget(const Eigen::Vector2f& target);

  const Eigen::Vector2f& target() const;

  State state() const;
  void setState(State state);

private:
  Eigen::Vector2f _target;
  State _state;
};


class EntityMovement : public EntityModule
{
public:
  EntityMovement(std::size_t entityId, float speedMax);
  virtual ~EntityMovement();

  Eigen::Vector2f position() const;
  float maxSpeed() const;

  bool setTarget(std::unique_ptr<MovementTarget> target);
  void setTarget(std::unique_ptr<MovementTarget> target, std::vector<TilePos> path);

  void update(float deltas);

protected:
  void computeSplinePath();

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _speedMax;    // nb pixels par seconde
  std::unique_ptr<MovementTarget> _target;

  std::vector<TilePos> _path;
  Eigen::Spline<float, 2, 1> _splinePath;
  float _pathTime;
  float _pathDuration;
};

} // core

#endif // ENTITYMOVEMENT_H
