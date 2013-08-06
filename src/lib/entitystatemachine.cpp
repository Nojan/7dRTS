// associated header
#include "entitystatemachine.h"

// include
// core
#include "entitymanager.h"
#include "entitymovement.h"
#include "entityposition.h"
#include "entityteam.h"
#include "entityweapon.h"
#include "gameworld.h"

namespace core
{

size_t closestEnemyId(std::size_t id)
{
  float shortDistance = FLT_MAX;
  size_t shortId = -1;
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  const EntityPosition* selfPosModule = entityManager.positionModule(id);
  const EntityTeam* selfTeamModule = entityManager.teamModule(id);
  EntityTeam::Team selfTeam = selfTeamModule->team();
  const Eigen::Vector2f selfPosition = selfPosModule->position();
  const size_t entityCount = entityManager.entityCount();
  for(std::size_t i = 0; i<entityCount; ++i)
  {
    const EntityPosition* otherPosition = entityManager.positionModule(i);
    const EntityTeam* otherTeamModule = entityManager.teamModule(i);
    if(otherPosition && otherTeamModule && selfTeam != otherTeamModule->team() && i != id)
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



EntityStateMachine::EntityStateMachine(std::size_t entityId)
  :EntityModule(entityId)
{
}

void EntityStateMachine::update()
{
  const size_t enemy = closestEnemyId(entityId());
  EntityManager& entityManager = GameWorld::Instance().entityManager();
  if(static_cast<size_t>(-1) != enemy)
  {
    const EntityPosition* positionEnemy = entityManager.positionModule(enemy);
    EntityWeapon* weapon = entityManager.weaponModule(entityId());
    EntityMovement* movement = entityManager.movementModule(entityId());
    if(!weapon->canShootAt(positionEnemy->position()))
    {

      movement->setTarget(std::unique_ptr<MovementTarget>(
                            new MovementTarget(positionEnemy->position())));
    }
    else
    {
      movement->setTarget(std::unique_ptr<MovementTarget>());
    }
    weapon->setTarget(new WeaponTarget(enemy));
  }
  else
  {
    // A chier, gestion de la mort a faire par module
    EntityMovement* movement = entityManager.movementModule(entityId());
    movement->setTarget(NULL);
    EntityWeapon* weapon = entityManager.weaponModule(entityId());
    weapon->setTarget(NULL);
  }
}

} // core
