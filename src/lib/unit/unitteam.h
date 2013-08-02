#ifndef UNITTEAM_H
#define UNITTEAM_H

// include
// core
#include "entityteam.h"

namespace core
{

class UnitTeam : public EntityTeam
{
public:
  UnitTeam(std::size_t eId, Team team)
    : EntityTeam(eId, team)
  { }
};

} // core

#endif // UNITTEAM_H
