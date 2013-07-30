#include "entitygraphicholder.h"

#include "entitymanager.h"
#include "entityposition.h"
#include "gameworld.h"
#include "graphicentity.h"

EntityGraphicHolder::EntityGraphicHolder(size_t entityId, GraphicEntity *entityGraphics)
  : EntityModule(entityId)
  , _entityGraphics(entityGraphics)
{

}

EntityGraphicHolder::~EntityGraphicHolder()
{
  if(QGraphicsScene * scene =_entityGraphics->scene())
  {
    scene->removeItem(_entityGraphics);
  }
  delete _entityGraphics;
}

const GraphicEntity *EntityGraphicHolder::graphic() const
{
  return _entityGraphics;
}

void EntityGraphicHolder::update()
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  EntityPosition* position = entityManager.positionModule(entityId());
  _entityGraphics->setPosition(position->position().x(), position->position().y());
}
