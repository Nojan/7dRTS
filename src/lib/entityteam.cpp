// associated header
#include "entityteam.h"

namespace core
{

EntityTeam::EntityTeam(std::size_t entityId, Team team)
  : EntityModule(entityId)
  , _team(team)
{
}

EntityTeam::Team EntityTeam::team() const
{
  return _team;
}

QBrush EntityTeam::brushFromTeamId(const EntityTeam::Team teamId)
{
    Qt::GlobalColor color;
    switch(teamId)
    {
        case EntityTeam::TeamA :
            color = Qt::blue;
            break;
        case EntityTeam::TeamB :
            color = Qt::red;
            break;
        default:
            color = Qt::yellow;
            break;
    }
    return color;
}

} // core
