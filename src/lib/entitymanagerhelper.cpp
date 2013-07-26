#include "entitymanagerhelper.h"

#include "entitydamage.h"
#include "entitygraphicholder.h"
#include "entitymovement.h"
#include "entityposition.h"
#include "entitystatemachine.h"
#include "entityteam.h"
#include "entityweapon.h"

size_t EntityManagerHelpers::
createSimpleUnit(GraphicEntity *graphicEntity,
                 Eigen::Vector2f position,
                 EntityTeam::Team teamId)
{
  EntityManager& entityManager = EntityManager::Instance();
  const size_t entityId = entityManager.createEntityId();
  entityManager.registerDamageModule(new EntityDamage(entityId));
  entityManager.registerPositionModule(new EntityPosition(entityId, position));
  entityManager.registerMovementModule(new EntityMovement(entityId));
  entityManager.registerGraphicHolderModule(new EntityGraphicHolder(entityId, graphicEntity));
  entityManager.registerStateMachineModule(new EntityStateMachine(entityId));
  entityManager.registerTeamModule(new EntityTeam(entityId, teamId));
  entityManager.registerWeaponModule(new EntityWeapon(entityId));
  return entityId;
}
