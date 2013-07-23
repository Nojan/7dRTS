#include "entityposition.h"

EntityPosition::EntityPosition(size_t entityId)
  : EntityModule(entityId)
{
}

Eigen::Vector2i EntityPosition::position()
{
  return _position;
}

void EntityPosition::setPosition(const Eigen::Vector2i position)
{
  _position = position;
}
