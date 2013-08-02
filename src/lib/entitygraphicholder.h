#ifndef ENTITYGRAPHICHOLDER_H
#define ENTITYGRAPHICHOLDER_H

// include
// core
#include "entitymodule.h"
#include "gameworld.h"

// forward declaration
namespace graphic
{
class GraphicEntity;
}

namespace core
{

class EntityGraphicHolder : public EntityModule
{
public:
  EntityGraphicHolder(std::size_t entityId,
                      graphic::GraphicEntity* entityGraphics);
  virtual ~EntityGraphicHolder();

  const graphic::GraphicEntity* graphic() const;


  void update();

private:
  graphic::GraphicEntity* _entityGraphics;

};

} // core

#endif // ENTITYGRAPHICHOLDER_H
