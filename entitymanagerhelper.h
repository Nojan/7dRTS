#ifndef ENTITYMANAGERHELPER_H
#define ENTITYMANAGERHELPER_H
#include "pch.h"

#include "entitymanager.h"
#include "entityteam.h"

class GraphicEntity;

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

}

#endif // ENTITYMANAGERHELPER_H
