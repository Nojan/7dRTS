// associated header
#include "entitymanager.h"

// include
// core
#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entitymovement.h"
#include "entitymodule.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"
#include "entityweapon.h"

namespace core
{

EntityManager::EntityManager()
  : _maxEntity()
{
  _modules.resize(moduleType::length);
}

size_t EntityManager::entityCount() const
{
  return _maxEntity;
}

size_t EntityManager::createEntityId()
{
  const size_t entityId = _maxEntity;
  ++_maxEntity;

  for(std::vector<EntityModule*>& moduleVector : _modules)
  {
    moduleVector.push_back(NULL);
    assert(moduleVector.size() == _maxEntity);
  }
  return entityId;
}

void EntityManager::deferredRemoveEntity(std::size_t entityId)
{
  _entityToRemove.push_back(entityId);
}

void EntityManager::removeEntity(std::size_t entityId)
{
  for(std::vector<EntityModule*>& module : _modules)
  {
    if(module[entityId])
    {
      delete module[entityId];
      module[entityId] = NULL;
    }
  }
}

void EntityManager::processRemoveEntity()
{
  for(std::size_t entityId : _entityToRemove)
  {
    // warn module of death of entityId
    for(std::vector<EntityModule*>& module : _modules)
    {
      for(EntityModule* moduleInstance : module)
      {
        if(moduleInstance)
          moduleInstance->processDeadEntity(entityId);
      }
    }
    // remove the dead entity
    removeEntity(entityId);
  }
  _entityToRemove.clear();
}

void EntityManager::processModules(int deltaMs)
{
  for(std::vector<EntityModule*>& moduleVector : _modules)
  {
    for(EntityModule* module : moduleVector)
    {
      if(module)
        module->update(deltaMs);
    }
  }
  processRemoveEntity();
}

void EntityManager::registerModule(EntityModule *module, EntityManager::moduleType type)
{
  assert(NULL != module);
  const std::size_t entityId = module->entityId();
  assert(entityId < _maxEntity);
  std::vector<EntityModule*>& moduleVector = _modules[type];
  assert(_maxEntity == moduleVector.size());
  assert(NULL == moduleVector[entityId]);
  moduleVector[entityId] = module;
}

EntityModule *EntityManager::module(std::size_t entityId, moduleType type)
{
  assert(entityId < _maxEntity);
  std::vector<EntityModule*>& moduleVector = _modules[type];
  return moduleVector[entityId];
}

void EntityManager::registerDamageModule(EntityDamage *module)
{
  registerModule(module, EntityManager::damage);
}

EntityDamage *EntityManager::damageModule(std::size_t entityId)
{
  return static_cast<EntityDamage*> (module(entityId, EntityManager::damage));
}

void EntityManager::registerMovementModule(EntityMovement *module)
{
  registerModule(module, EntityManager::movement);
}

EntityMovement *EntityManager::movementModule(std::size_t entityId)
{
  return static_cast<EntityMovement*> (module(entityId, EntityManager::movement));
}

void EntityManager::registerPositionModule(EntityPosition *module)
{
  registerModule(module, EntityManager::position);
}

EntityPosition *EntityManager::positionModule(std::size_t entityId)
{
  return static_cast<EntityPosition*> (module(entityId, EntityManager::position));
}

void EntityManager::registerGraphicHolderModule(EntityGraphicHolder *module)
{
  registerModule(module, EntityManager::graphicHolder);
}

EntityGraphicHolder *EntityManager::GraphicHolderModule(std::size_t entityId)
{
  return static_cast<EntityGraphicHolder*> (module(entityId, EntityManager::graphicHolder));
}

void EntityManager::registerStateMachineModule(EntityStateMachine *module)
{
  registerModule(module, EntityManager::stateMachine);
}

EntityStateMachine *EntityManager::stateMachineModule(std::size_t entityId)
{
  return static_cast<EntityStateMachine*> (module(entityId, EntityManager::stateMachine));
}

void EntityManager::registerTeamModule(EntityTeam *module)
{
  registerModule(module, EntityManager::team);
}

EntityTeam *EntityManager::teamModule(std::size_t entityId)
{
return static_cast<EntityTeam*> (module(entityId, EntityManager::team));
}

void EntityManager::registerWeaponModule(EntityWeapon *module)
{
  registerModule(module, EntityManager::weapon);
}

EntityWeapon *EntityManager::weaponModule(std::size_t entityId)
{
return static_cast<EntityWeapon*> (module(entityId, EntityManager::weapon));
}

} // core
