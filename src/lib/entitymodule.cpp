// associated header
#include "entitymodule.h"

namespace core
{

EntityModule::EntityModule(std::size_t entityId)
  : _entityId(entityId)
{
}

std::size_t EntityModule::entityId() const
{
  return _entityId;
}

void EntityModule::update(const int deltaMs)
{
}

void EntityModule::processDeadEntity(const std::size_t entityId)
{
}

} // core
