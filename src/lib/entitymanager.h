#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

// include
// pch
#include "pch.h"

// std
#include <cstdlib>


// forward declaration
namespace core
{
class EntityDamage;
class EntityGraphicHolder;
class EntityModule;
class EntityMovement;
class EntityStateMachine;
class EntityTeam;
class EntityWeapon;
class EntityPosition;
}

namespace core
{

class EntityManager
{
public:
  enum moduleType
  {
    movement,
    position,
    graphicHolder,
    stateMachine,
    team,
    weapon,
    damage,
    length
  };

  EntityManager();

  size_t entityCount() const;
  size_t createEntityId();
  void   deferredRemoveEntity(std::size_t entityId);

  void processModules(int deltaMs);

  void registerModule(EntityModule* module, moduleType type);
  EntityModule* module(std::size_t entityId, moduleType type);

  void registerDamageModule(EntityDamage* module);
  EntityDamage* damageModule(std::size_t entityId);

  void registerMovementModule(EntityMovement* module);
  EntityMovement* movementModule(std::size_t entityId);

  void registerPositionModule(EntityPosition* module);
  EntityPosition* positionModule(std::size_t entityId);

  void registerGraphicHolderModule(EntityGraphicHolder* module);
  EntityGraphicHolder* GraphicHolderModule(std::size_t entityId);

  void registerStateMachineModule(EntityStateMachine* module);
  EntityStateMachine* stateMachineModule(std::size_t entityId);

  void registerTeamModule(EntityTeam* module);
  EntityTeam* teamModule(std::size_t entityId);

  void registerWeaponModule(EntityWeapon* module);
  EntityWeapon* weaponModule(std::size_t entityId);

private:
  void removeEntity(std::size_t entityId);
  void processRemoveEntity();

private:
  std::size_t _maxEntity;
  std::vector< std::vector<EntityModule*> > _modules;

  std::vector<std::size_t> _entityToRemove;
};

} // core

#endif // ENTITYMANAGER_H
