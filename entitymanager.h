#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "pch.h"

#include <stdlib.h>
#include <vector>

class EntityGraphicHolder;
class EntityModule;
class EntityMovement;
class EntityStateMachine;
class EntityTeam;
class EntityPosition;
class GraphicEntity;

class EntityManager
{
public:
  static EntityManager& Instance();

  size_t createEntityId();

  void processModules(int deltaMs);

  void registerMovementModule(EntityMovement* module);
  EntityMovement* movementModule(size_t entityId);

  void registerPositionModule(EntityPosition* module);
  EntityPosition* positionModule(size_t entityId);

  void registerGraphicHolderModule(EntityGraphicHolder* module);
  EntityGraphicHolder* GraphicHolderModule(size_t entityId);

  void registerStateMachineModule(EntityStateMachine* module);
  EntityStateMachine* stateMachineModule(size_t entityId);

  void registerTeamModule(EntityTeam* module);
  EntityTeam* TeamModule(size_t entityId);

private:
  EntityManager();

private:
  size_t _maxEntity;
  std::vector<EntityMovement*> _movementModules;
  std::vector<EntityPosition*> _positionModules;
  std::vector<EntityGraphicHolder*> _graphicHolderModules;
  std::vector<EntityStateMachine*> _stateMachineModules;
  std::vector<EntityTeam*> _teamModules;
};

namespace EntityManagerHelpers
{
size_t createSimpleUnit(GraphicEntity* graphicEntity);
}

#endif // ENTITYMANAGER_H
