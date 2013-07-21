#ifndef ENTITYMODULE_H
#define ENTITYMODULE_H

#include <stdlib.h>

class EntityModule
{
public:
  EntityModule(size_t entityId);

  size_t entityId() const;

private:
  size_t _entityId;
};

#endif // ENTITYMODULE_H
