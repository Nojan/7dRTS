#ifndef ENTITYTEAMMODULE_H
#define ENTITYTEAMMODULE_H

#include "entitymodule.h"

#include <QApplication>
#include <QtWidgets>

class EntityTeam : public EntityModule
{
public:
  enum Team {
    TeamA,
    TeamB,
    Invalid
  };

  EntityTeam(size_t entityId, Team team);

  Team team() const;

  static QBrush brushFromTeamId(const EntityTeam::Team teamId);


private:
  Team _team;
  Qt::GlobalColor _color;
};

#endif // ENTITYTEAMMODULE_H
