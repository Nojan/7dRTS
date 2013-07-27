#include "entitygraphicholder.h"

#include "entitymanager.h"
#include "entityposition.h"
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

void EntityGraphicHolder::update()
{
  EntityManager& entityManager = EntityManager::Instance();
  EntityPosition* position = entityManager.positionModule(entityId());
  _entityGraphics->setPosition(position->position().x(), position->position().y());
}
