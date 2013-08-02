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

} // core
