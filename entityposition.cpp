#include "entityposition.h"

EntityPosition::EntityPosition(size_t entityId)
  : EntityModule(entityId)
{
}

int2 EntityPosition::position()
{
  return _position;
}

void EntityPosition::setPosition(const int2 position)
{
  _position = position;
}
