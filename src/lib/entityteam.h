#ifndef ENTITYTEAMMODULE_H
#define ENTITYTEAMMODULE_H

// include
// Qt
#include <QApplication>
#include <QtWidgets>

// core
#include "entitymodule.h"

namespace core
{

class EntityTeam : public EntityModule
{
public:
  enum Team {
    TeamA,
    TeamB,
    Invalid
  };

  EntityTeam(std::size_t entityId, Team team);

  Team team() const;

  static QBrush brushFromTeamId(const EntityTeam::Team teamId);


private:
  Team _team;
  Qt::GlobalColor _color;
};

} // core

#endif // ENTITYTEAMMODULE_H
