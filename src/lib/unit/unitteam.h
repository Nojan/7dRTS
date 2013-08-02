#ifndef UNITTEAM_H
#define UNITTEAM_H

// include
// core
#include "entityteam.h"

class UnitTeam : public EntityTeam
{
public:
  UnitTeam(size_t eId, Team team)
    : EntityTeam(eId, team)
  { }
};

#endif // UNITTEAM_H
