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
                        Eigen::Vector2f position,
                        EntityTeam::Team teamId);

size_t createUnitGrosDegats(GraphicEntity* graphicEntity,
                        Eigen::Vector2f position,
                        EntityTeam::Team teamId);

size_t createUnitRapide(GraphicEntity* graphicEntity,
                        Eigen::Vector2f position,
                        EntityTeam::Team teamId);

size_t createUnitTank(GraphicEntity* graphicEntity,
                        Eigen::Vector2f position,
                        EntityTeam::Team teamId);

size_t createUnitDoor(graphic::GraphicDoor* graphicDoor,
                      Eigen::Vector2f position,
                      EntityTeam::Team teamId);

} // EntityManagerHelpers

#endif // ENTITYMANAGERHELPER_H
