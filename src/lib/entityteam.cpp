#include "entityteam.h"

EntityTeam::EntityTeam(size_t entityId, Team team)
  : EntityModule(entityId)
  , _team(team)
{
}

EntityTeam::Team EntityTeam::team() const
{
  return _team;
}
