#include "entityteam.h"

EntityTeam::EntityTeam(size_t entityId)
  : EntityModule(entityId)
  , _team(EntityTeam::Team::Invalid)
{
}

EntityTeam::Team EntityTeam::team() const
{
  return _team;
}
