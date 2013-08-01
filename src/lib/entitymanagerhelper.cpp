// associated header
#include "entitymanagerhelper.h"

// include
// core
#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entitymovement.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"
#include "entityweapon.h"
#include "gameworld.h"

// graphic
#include "graphicdoor.h"


namespace EntityManagerHelpers
{

size_t
createSimpleUnit(GraphicEntity *graphicEntity,
                 const Eigen::Vector2f& position,
                 EntityTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new EntityDamage(entityId, 100));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerMovementModule(new EntityMovement(entityId, 1));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  entityManager.registerWeaponModule(new EntityWeapon(entityId, 10, 10.f, 2000));
  return entityId;
}

size_t
createUnitGrosDegats(GraphicEntity *graphicEntity,
                 const Eigen::Vector2f& position,
                 EntityTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new EntityDamage(entityId, 100));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerMovementModule(new EntityMovement(entityId, 1));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  entityManager.registerWeaponModule(new EntityWeapon(entityId, 20, 10.f, 2000));
  return entityId;
}

size_t
createUnitRapide(GraphicEntity *graphicEntity,
                 const Eigen::Vector2f& position,
                 EntityTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new EntityDamage(entityId, 100));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerMovementModule(new EntityMovement(entityId, 2));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  entityManager.registerWeaponModule(new EntityWeapon(entityId, 5, 10.f, 2000));
  return entityId;
}


size_t
createUnitTank(GraphicEntity *graphicEntity,
                 const Eigen::Vector2f& position,
                 EntityTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new EntityDamage(entityId, 200));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerMovementModule(new EntityMovement(entityId, 0.5f));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  entityManager.registerWeaponModule(new EntityWeapon(entityId, 30, 5.f, 2000));
  return entityId;
}


size_t
createUnitDoor(graphic::GraphicDoor* graphicDoor,
               const Eigen::Vector2f& position,
               EntityTeam::Team teamId)
{
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const size_t entityId = entityManager.createEntityId();

  entityManager.registerDamageModule(new EntityDamage(entityId, 100));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicDoor));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  return entityId;
}

} // EntityManagerHelpers
