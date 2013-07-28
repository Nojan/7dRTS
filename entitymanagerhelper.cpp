#include "entitymanagerhelper.h"

#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entitymovement.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"
#include "entityweapon.h"
#include "gameworld.h"



size_t EntityManagerHelpers::
createSimpleUnit(GraphicEntity *graphicEntity,
                 Eigen::Vector2f position,
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

size_t EntityManagerHelpers::
createUnitGrosDegats(GraphicEntity *graphicEntity,
                 Eigen::Vector2f position,
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

size_t EntityManagerHelpers::
createUnitRapide(GraphicEntity *graphicEntity,
                 Eigen::Vector2f position,
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


size_t EntityManagerHelpers::
createUnitTank(GraphicEntity *graphicEntity,
                 Eigen::Vector2f position,
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
