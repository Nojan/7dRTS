#include "entitymodule.h"

EntityModule::EntityModule(size_t entityId)
  : _entityId(entityId)
{
}

size_t EntityModule::entityId() const
{
  return _entityId;
}
