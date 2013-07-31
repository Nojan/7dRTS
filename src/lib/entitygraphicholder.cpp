// associated header
#include "entitygraphicholder.h"

// core
#include "entitydamage.h"
#include "entitymanager.h"
#include "entityposition.h"
#include "gameworld.h"

// graphic
#include "graphicentity.h"


EntityGraphicHolder::EntityGraphicHolder(size_t entityId, GraphicEntity *entityGraphics)
  : EntityModule(entityId)
  , _entityGraphics(entityGraphics)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  if(entityManager.damageModule(entityId))
  {
    _entityGraphics->setHasHealthBar(true);
  }
  _entityGraphics->setEntityId(entityId);
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
  if(_entityGraphics->hasHealthBar())
  {
      float healthPercentage = float(entityManager.damageModule(entityId())->healthPoint())/float(entityManager.damageModule(entityId())->maxHealthPoint());
      _entityGraphics->setHealthPercentage(healthPercentage);
  }
  _entityGraphics->setPosition(position->position().x(), position->position().y());
}
