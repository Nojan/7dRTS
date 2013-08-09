// associated header
#include "entitymanagerhelper.h"

// include
// core
#include "door/doorgraphicholder.h"
#include "door/doorposition.h"
#include "door/doorstatemachine.h"
#include "unit/unitdamage.h"
#include "unit/unitgraphicholder.h"
#include "unit/unitmovement.h"
#include "unit/unitposition.h"
#include "unit/unitstatemachine.h"
#include "unit/unitteam.h"
#include "unit/unitweapon.h"
#include "gameworld.h"

// graphic
#include "door/graphicdoor.h"


namespace EntityManagerHelpers
{
using namespace core;

std::size_t
createSimpleUnit(graphic::GraphicUnit *graphicUnit,
                 const Eigen::Vector2f& position,
                 UnitTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new UnitDamage(entityId, 100));
  entityManager.registerPositionModule(new UnitPosition(entityId, position));
  entityManager.registerMovementModule(new UnitMovement(entityId, 1));
  entityManager.registerGraphicHolderModule(new UnitGraphicHolder(entityId, graphicUnit));
  entityManager.registerStateMachineModule(new UnitStateMachine(entityId));
  entityManager.registerTeamModule(new UnitTeam(entityId, teamId));
  entityManager.registerWeaponModule(new UnitWeapon(entityId, 10, 10.f, 2000));
  return entityId;
}

std::size_t
createUnitGrosDegats(graphic::GraphicUnit *graphicUnit,
                     const Eigen::Vector2f& position,
                     UnitTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new UnitDamage(entityId, 100));
  entityManager.registerPositionModule(new UnitPosition(entityId, position));
  entityManager.registerMovementModule(new UnitMovement(entityId, 1));
  entityManager.registerGraphicHolderModule(new UnitGraphicHolder(entityId, graphicUnit));
  entityManager.registerStateMachineModule(new UnitStateMachine(entityId));
  entityManager.registerTeamModule(new UnitTeam(entityId, teamId));
  entityManager.registerWeaponModule(new UnitWeapon(entityId, 20, 10.f, 2000));
  return entityId;
}

std::size_t
createUnitRapide(graphic::GraphicUnit *graphicUnit,
                 const Eigen::Vector2f& position,
                 UnitTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new UnitDamage(entityId, 100));
  entityManager.registerPositionModule(new UnitPosition(entityId, position));
  entityManager.registerMovementModule(new UnitMovement(entityId, 2));
  entityManager.registerGraphicHolderModule(new UnitGraphicHolder(entityId, graphicUnit));
  entityManager.registerStateMachineModule(new UnitStateMachine(entityId));
  entityManager.registerTeamModule(new UnitTeam(entityId, teamId));
  entityManager.registerWeaponModule(new UnitWeapon(entityId, 5, 10.f, 2000));
  return entityId;
}


std::size_t
createUnitTank(graphic::GraphicUnit *graphicUnit,
               const Eigen::Vector2f& position,
               UnitTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new UnitDamage(entityId, 200));
  entityManager.registerPositionModule(new UnitPosition(entityId, position));
  entityManager.registerMovementModule(new UnitMovement(entityId, 0.5f));
  entityManager.registerGraphicHolderModule(new UnitGraphicHolder(entityId, graphicUnit));
  entityManager.registerStateMachineModule(new UnitStateMachine(entityId));
  entityManager.registerTeamModule(new UnitTeam(entityId, teamId));
  entityManager.registerWeaponModule(new UnitWeapon(entityId, 30, 5.f, 2000));
  return entityId;
}


std::size_t
createUnitDoor(graphic::GraphicDoor* graphicDoor,
               const Eigen::Vector2f& position,
               const std::vector<core::EdgePos>& edges,
               UnitTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();

  entityManager.registerDamageModule(new EntityDamage(entityId, 100));
  entityManager.registerPositionModule(new DoorPosition(entityId, position, edges));
  entityManager.registerGraphicHolderModule(
        new DoorGraphicHolder(entityId, graphicDoor, position));
  entityManager.registerStateMachineModule(new DoorStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  return entityId;
}

} // EntityManagerHelpers
