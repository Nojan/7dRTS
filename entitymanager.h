#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "pch.h"

#include <stdlib.h>
#include <vector>

class EntityDamage;
class EntityGraphicHolder;
class EntityModule;
class EntityMovement;
class EntityStateMachine;
class EntityTeam;
class EntityWeapon;
class EntityPosition;
class GraphicEntity;

class EntityManager
{
public:
  static EntityManager& Instance();

  size_t entityCount() const;
  size_t createEntityId();
  void   deferredRemoveEntity(size_t entityId);

  void processModules(int deltaMs);

  void registerDamageModule(EntityDamage* module);
  EntityDamage* damageModule(size_t entityId);

  void registerMovementModule(EntityMovement* module);
  EntityMovement* movementModule(size_t entityId);

  void registerPositionModule(EntityPosition* module);
  EntityPosition* positionModule(size_t entityId);

  void registerGraphicHolderModule(EntityGraphicHolder* module);
  EntityGraphicHolder* GraphicHolderModule(size_t entityId);

  void registerStateMachineModule(EntityStateMachine* module);
  EntityStateMachine* stateMachineModule(size_t entityId);

  void registerTeamModule(EntityTeam* module);
  EntityTeam* teamModule(size_t entityId);

  void registerWeaponModule(EntityWeapon* module);
  EntityWeapon* weaponModule(size_t entityId);

private:
  EntityManager();
  void removeEntity(size_t entityId);
  void processRemoveEntity();

private:
  size_t _maxEntity;
  std::vector<EntityDamage*> _damageModules;
  std::vector<EntityMovement*> _movementModules;
  std::vector<EntityPosition*> _positionModules;
  std::vector<EntityGraphicHolder*> _graphicHolderModules;
  std::vector<EntityStateMachine*> _stateMachineModules;
  std::vector<EntityTeam*> _teamModules;
  std::vector<EntityWeapon*> _weaponModules;

  std::vector<size_t> _entityToRemove;
};

#endif // ENTITYMANAGER_H
