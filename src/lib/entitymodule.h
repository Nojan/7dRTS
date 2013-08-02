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

private:
  std::size_t _entityId;
};

} // core

#endif // ENTITYMODULE_H
