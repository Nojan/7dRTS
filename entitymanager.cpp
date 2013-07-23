#include "entitymanager.h"

#include "entitygraphicholder.h"
#include "entitymodule.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"

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
  _stateMachineModules.push_back(NULL);
  _teamModules.push_back(NULL);
  return entityId;
}

void EntityManager::processModules(int deltaMs)
{
  foreach(EntityPosition* positionModule, _positionModules)
  {
    positionModule->setPosition(positionModule->position()+Eigen::Vector2i(1,0));
  }
  foreach(EntityGraphicHolder* graphicModule, _graphicHolderModules)
  {
    graphicModule->update();
  }
  foreach(EntityStateMachine* stateMachineModule, _stateMachineModules)
  {
    stateMachineModule->update();
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

void EntityManager::registerStateMachineModule(EntityStateMachine *module)
{
  assert(NULL == _stateMachineModules[module->entityId()]);
  _stateMachineModules[module->entityId()] = module;
}

EntityStateMachine *EntityManager::stateMachineModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _stateMachineModules[entityId];
}

void EntityManager::registerTeamModule(EntityTeam *module)
{
  assert(NULL == _teamModules[module->entityId()]);
  _teamModules[module->entityId()] = module;
}

EntityTeam *EntityManager::TeamModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _teamModules[entityId];
}

size_t EntityManagerHelpers::createSimpleUnit(GraphicEntity *graphicEntity)
{
  EntityManager& entityManager = EntityManager::Instance();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerPositionModule(new EntityPosition(entityId));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId));
  return entityId;
}
