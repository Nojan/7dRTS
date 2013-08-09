#ifndef ENTITYMANAGERHELPER_H
#define ENTITYMANAGERHELPER_H

// include
// pch
#include "pch.h"

// core
#include "entitymanager.h"
#include "entityteam.h"


// forward declaration
namespace core
{
class EdgePos;
}
namespace graphic
{
class GraphicDoor;
class GraphicUnit;
}

namespace EntityManagerHelpers
{

std::size_t createSimpleUnit(graphic::GraphicUnit* graphicUnit,
                             const Eigen::Vector2f& position,
                             core::EntityTeam::Team teamId);

std::size_t createUnitGrosDegats(graphic::GraphicUnit* graphicUnit,
                                 const Eigen::Vector2f& position,
                                 core::EntityTeam::Team teamId);

std::size_t createUnitRapide(graphic::GraphicUnit* graphicUnit,
                             const Eigen::Vector2f& position,
                             core::EntityTeam::Team teamId);

std::size_t createUnitTank(graphic::GraphicUnit* graphicUnit,
                           const Eigen::Vector2f& position,
                           core::EntityTeam::Team teamId);

std::size_t createUnitDoor(graphic::GraphicDoor* graphicDoor,
                           const Eigen::Vector2f& position,
                           const std::vector<core::EdgePos>& edges,
                           core::EntityTeam::Team teamId);

} // EntityManagerHelpers

#endif // ENTITYMANAGERHELPER_H
