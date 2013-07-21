#include "entitymanager.h"

#include "entitygraphicholder.h"
#include "entitymodule.h"
#include "entityposition.h"

#include <assert.h>

EntityManager& EntityManager::Instance()
{
    static EntityManager instance;
    return instance;
}

EntityManager::EntityManager()
  : _maxEntity()
{
}

size_t EntityManager::createEntityId()
{
  const size_t entityId = _maxEntity;
  ++_maxEntity;
  _positionModules.push_back(NULL);
  _graphicHolderModules.push_back(NULL);
  return entityId;
}

void EntityManager::processModules(int deltaMs)
{
  foreach(EntityPosition* positionModule, _positionModules)
  {
    positionModule->setPosition(positionModule->position()+int2(1,0));
  }
  foreach(EntityGraphicHolder* graphicModule, _graphicHolderModules)
  {
    graphicModule->update();
  }
}

void EntityManager::registerPositionModule(EntityPosition *module)
{
  assert(NULL == _positionModules[module->entityId()]);
  _positionModules[module->entityId()] = module;
}

EntityPosition *EntityManager::positionModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _positionModules[entityId];
}

void EntityManager::registerGraphicHolderModule(EntityGraphicHolder *module)
{
  assert(NULL == _graphicHolderModules[module->entityId()]);
  _graphicHolderModules[module->entityId()] = module;
}

EntityGraphicHolder *EntityManager::GraphicHolderModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _graphicHolderModules[entityId];
}


size_t EntityManagerHelpers::createSimpleUnit(GraphicEntity *graphicEntity)
{
  EntityManager& entityManager = EntityManager::Instance();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerPositionModule(new EntityPosition(entityId));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  return entityId;
}
