#ifndef ENTITYMODULE_H
#define ENTITYMODULE_H

// include
// std
#include <cstdlib>

namespace core
{

class EntityModule
{
public:
  EntityModule(std::size_t entityId);

  std::size_t entityId() const;

  // Each module must reimplement this method if they are storing entityId
  // This way, they will be warn of the removal of such entity.
  virtual void processDeadEntity(const std::size_t entityId);

private:
  std::size_t _entityId;
};

} // core

#endif // ENTITYMODULE_H
