#ifndef ENTITYMANAGERHELPER_H
#define ENTITYMANAGERHELPER_H
#include "pch.h"

#include "entitymanager.h"
#include "entityteam.h"


// forward declaration
class GraphicEntity;
namespace graphic
{
class GraphicDoor;
}

namespace EntityManagerHelpers
{

size_t createSimpleUnit(GraphicEntity* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitGrosDegats(GraphicEntity* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitRapide(GraphicEntity* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitTank(GraphicEntity* graphicEntity,
                        const Eigen::Vector2f& position,
                        EntityTeam::Team teamId);

size_t createUnitDoor(graphic::GraphicDoor* graphicDoor,
                      const Eigen::Vector2f& position,
                      EntityTeam::Team teamId);

} // EntityManagerHelpers

#endif // ENTITYMANAGERHELPER_H
