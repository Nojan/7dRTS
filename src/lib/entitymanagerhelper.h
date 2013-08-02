#ifndef ENTITYMANAGERHELPER_H
#define ENTITYMANAGERHELPER_H
#include "pch.h"

#include "entitymanager.h"
#include "entityteam.h"


// forward declaration
class GraphicUnit;
namespace graphic
{
class GraphicDoor;
}

namespace EntityManagerHelpers
{

size_t createSimpleUnit(GraphicUnit* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitGrosDegats(GraphicUnit* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitRapide(GraphicUnit* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitTank(GraphicUnit* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitDoor(graphic::GraphicDoor* graphicDoor,
                      const Eigen::Vector2f& position,
                      EntityTeam::Team teamId);

} // EntityManagerHelpers

#endif // ENTITYMANAGERHELPER_H
