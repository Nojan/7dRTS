#include "entitymanager.h"

#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entitymovement.h"
#include "entitymodule.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"
#include "entityweapon.h"

EntityManager::EntityManager()
  : _maxEntity()
{
}

size_t EntityManager::entityCount() const
{
  return _maxEntity;
}

size_t EntityManager::createEntityId()
{
  const size_t entityId = _maxEntity;
  ++_maxEntity;
  _damageModules.push_back(NULL);
  _movementModules.push_back(NULL);
  _positionModules.push_back(NULL);
  _graphicHolderModules.push_back(NULL);
  _stateMachineModules.push_back(NULL);
  _teamModules.push_back(NULL);
  _weaponModules.push_back(NULL);
  return entityId;
}

void EntityManager::deferredRemoveEntity(size_t entityId)
{
  _entityToRemove.push_back(entityId);
}

void EntityManager::removeEntity(size_t entityId)
{
  if(_damageModules[entityId])
  {
    delete _damageModules[entityId];
    _damageModules[entityId] = NULL;
  }
  if(_movementModules[entityId])
  {
    delete _movementModules[entityId];
    _movementModules[entityId] = NULL;
  }
  if(_positionModules[entityId])
  {
    delete _positionModules[entityId];
    _positionModules[entityId] = NULL;
  }
  if(_graphicHolderModules[entityId])
  {
    delete _graphicHolderModules[entityId];
    _graphicHolderModules[entityId] = NULL;
  }
  if(_stateMachineModules[entityId])
  {
    delete _stateMachineModules[entityId];
    _stateMachineModules[entityId] = NULL;
  }
  if(_teamModules[entityId])
  {
    delete _teamModules[entityId];
    _teamModules[entityId] = NULL;
  }
  if(_weaponModules[entityId])
  {
    delete _weaponModules[entityId];
    _weaponModules[entityId] = NULL;
  }
}

void EntityManager::processRemoveEntity()
{
  foreach(size_t entityId, _entityToRemove)
  {
    removeEntity(entityId);
  }
  _entityToRemove.clear();
}

void EntityManager::processModules(int deltaMs)
{
  const float fdeltaS = static_cast<float>(deltaMs)/1000.f;
  foreach(EntityMovement* movementModule, _movementModules)
  {
    if(movementModule)
      movementModule->update(fdeltaS);
  }
  foreach(EntityPosition* positionModule, _positionModules)
  {
    if(positionModule)
      positionModule->update();
  }
  foreach(EntityGraphicHolder* graphicModule, _graphicHolderModules)
  {
    if(graphicModule)
      graphicModule->update();
  }
  foreach(EntityStateMachine* stateMachineModule, _stateMachineModules)
  {
    if(stateMachineModule)
      stateMachineModule->update();
  }
  foreach(EntityWeapon* weaponModule, _weaponModules)
  {
    if(weaponModule)
      weaponModule->update(deltaMs);
  }
  foreach(EntityDamage* damageModule, _damageModules)
  {
    if(damageModule)
      damageModule->update();
  }

  processRemoveEntity();
}

void EntityManager::registerDamageModule(EntityDamage *module)
{
  assert(NULL == _damageModules[module->entityId()]);
  _damageModules[module->entityId()] = module;
}

EntityDamage *EntityManager::damageModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _damageModules[entityId];
}

void EntityManager::registerMovementModule(EntityMovement *module)
{
  assert(NULL == _movementModules[module->entityId()]);
  _movementModules[module->entityId()] = module;
}

EntityMovement *EntityManager::movementModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _movementModules[entityId];
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

EntityTeam *EntityManager::teamModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _teamModules[entityId];
}

void EntityManager::registerWeaponModule(EntityWeapon *module)
{
  assert(NULL == _weaponModules[module->entityId()]);
  _weaponModules[module->entityId()] = module;
}

EntityWeapon *EntityManager::weaponModule(size_t entityId)
{
  assert(entityId < _maxEntity);
  return _weaponModules[entityId];
}
