#ifndef ENTITYGRAPHICHOLDER_H
#define ENTITYGRAPHICHOLDER_H

// include
// core
#include "entitymodule.h"


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


  virtual void update(const int deltaMs) override;

private:
  graphic::GraphicEntity* _entityGraphics;

};

} // core

#endif // ENTITYGRAPHICHOLDER_H
