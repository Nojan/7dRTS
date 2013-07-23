#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H
#include "pch.h"

#include "entitymodule.h"

class EntityPosition : public EntityModule
{
public:
  EntityPosition(size_t entityId);

  Eigen::Vector2f position();
  void setPosition(const Eigen::Vector2f position);

  void update();

private:
  Eigen::Vector2f _position;
};

#endif // ENTITYPOSITION_H
