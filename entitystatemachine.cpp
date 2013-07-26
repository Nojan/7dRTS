#include "entitystatemachine.h"

#include "entitymanager.h"
#include "entitymovement.h"
#include "entityposition.h"
#include "entityteam.h"
#include "entityweapon.h"

namespace {
size_t closestEnemyId(size_t id)
{
  float shortDistance = FLT_MAX;
  size_t shortId = -1;
  const EntityPosition* selfPosModule = EntityManager::Instance().positionModule(id);
  const EntityTeam* selfTeamModule = EntityManager::Instance().teamModule(id);
  EntityTeam::Team selfTeam = selfTeamModule->team();
  const Eigen::Vector2f selfPosition = selfPosModule->position();
  const size_t entityCount = EntityManager::Instance().entityCount();
  for(size_t i = 0; i<entityCount; ++i)
  {
    const EntityPosition* otherPosition = EntityManager::Instance().positionModule(i);
    const EntityTeam* otherTeamModule = EntityManager::Instance().teamModule(i);
    EntityTeam::Team otherTeam = otherTeamModule->team();
    if(otherPosition && selfTeam != otherTeam && i != id)
    {
      const float distance = (otherPosition->position() - selfPosition).norm();
      if ( distance < shortDistance )
      {
        shortDistance = distance;
        shortId = i;
      }
    }
  }
  return shortId;
}
}

EntityStateMachine::EntityStateMachine(size_t entityId)
  :EntityModule(entityId)
{
}

void EntityStateMachine::update()
{
  const size_t enemy = closestEnemyId(entityId());
  if(static_cast<size_t>(-1) != enemy)
  {
    const EntityPosition* position = EntityManager::Instance().positionModule(enemy);
    EntityMovement* movement = EntityManager::Instance().movementModule(entityId());
    movement->SetTarget(new MovememtTarget(position->position()));
    EntityWeapon* weapon = EntityManager::Instance().weaponModule(entityId());
    weapon->setTarget(new WeaponTarget(enemy));
  }
  else
  {
    // A chier, gestion de la mort a faire par module
    EntityMovement* movement = EntityManager::Instance().movementModule(entityId());
    movement->SetTarget(NULL);
    EntityWeapon* weapon = EntityManager::Instance().weaponModule(entityId());
    weapon->setTarget(NULL);
  }
}
