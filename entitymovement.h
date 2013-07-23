#ifndef ENTITYMOVEMENT_H
#define ENTITYMOVEMENT_H

#include "pch.h"

#include "entitymodule.h"

class EntityMovement : public EntityModule
{
public:
  EntityMovement(size_t entityId);

  Eigen::Vector2f position() const;

  void update(float deltas);

private:
  Eigen::Vector2f _position;
  Eigen::Vector2f _orientation;
  int _speedMax;
};

#endif // ENTITYMOVEMENT_H
