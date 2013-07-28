#ifndef ENTITYGRAPHICHOLDER_H
#define ENTITYGRAPHICHOLDER_H

#include "entitymodule.h"

#include "gameworld.h"

class GraphicEntity;

class EntityGraphicHolder : public EntityModule
{
public:
  EntityGraphicHolder(size_t entityId, GraphicEntity* entityGraphics);
  ~EntityGraphicHolder();

  const GraphicEntity* graphic() const;

  void update();

private:
  GraphicEntity* _entityGraphics;
};

#endif // ENTITYGRAPHICHOLDER_H
