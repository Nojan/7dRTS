// associated header
#include "unitcontroller.h"

// include
// core
#include "gameworld.h"
#include "entitymovement.h"
#include "entityposition.h"

namespace core
{

void UnitController::selectedUnit(std::vector<std::size_t> su)
{
  _selectedUnit = std::move(su);
}


const std::vector<std::size_t> UnitController::selectedUnit() const
{
  return _selectedUnit;
}


void UnitController::selectedTarget(const Eigen::Vector2i& target)
{
  EntityManager& em = GameWorld::Instance().entityManager();
  for(auto id: _selectedUnit)
  {
    EntityMovement* emm = em.movementModule(id);
    if(emm)
    {
      emm->setTarget(new MovementTarget(em.positionModule(id)->position(),
                                        target.cast<float>(), emm->maxSpeed()));
    }
  }
}

} // core
