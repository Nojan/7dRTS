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
  : EntityModule(entityId)
  , _state(State::Idle)
{
}


void EntityStateMachine::move(const Eigen::Vector2f& target)
{
  EntityManager& entityManager = gameworld().entityManager();
  std::unique_ptr<MovementTarget> mt(new MovementTarget(target.cast<float>()));
  entityManager.movementModule(entityId())->setTarget(std::move(mt));
  _state = State::Move;
  ///@todo find a mechanism to cleanup the old state
}


void EntityStateMachine::update(const int deltaMs)
{
  if(_state == State::Idle)
  {
    // we look for enemy
    const size_t enemy = closestEnemyId(entityId());
    EntityManager& entityManager = gameworld().entityManager();

    // enemy found
    if(static_cast<size_t>(-1) != enemy)
    {
      const EntityPosition* positionEnemy = entityManager.positionModule(enemy);
      EntityWeapon* weapon = entityManager.weaponModule(entityId());
      if(NULL == weapon)
        return; //nothing to do
      EntityMovement* movement = entityManager.movementModule(entityId());
      if(!weapon->canShootAt(positionEnemy->position()))
      {
        movement->setTarget(std::unique_ptr<MovementTarget>(
                              new MovementTarget(positionEnemy->position())));
        _state = State::MoveToFight;
      }
      weapon->setTarget(new WeaponTarget(enemy));
    }
  }
  else if(_state == State::Move)
  {
    EntityManager& entityManager = gameworld().entityManager();
    EntityMovement* movement = entityManager.movementModule(entityId());
    if(movement->movementTargetState() == MovementTarget::Done ||
       movement->movementTargetState() == MovementTarget::Abort)
    {
      _state = State::Idle;
    }
  }
  else if(_state == State::MoveToFight)
  {
    ///@todo follow targeted enemy
  }
  else if(_state == State::Fight)
  {
    ///@todo don't know...
  }
}

} // core
