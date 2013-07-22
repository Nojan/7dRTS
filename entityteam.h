#ifndef ENTITYTEAMMODULE_H
#define ENTITYTEAMMODULE_H

#include "entitymodule.h"

class EntityTeam : public EntityModule
{
public:
  enum Team {
    TeamA,
    TeamB,
    Invalid
  };

  EntityTeam(size_t entityId);

  Team team() const;

private:
  Team _team;
};

#endif // ENTITYTEAMMODULE_H
