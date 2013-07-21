#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <stdlib.h>
#include <vector>

class EntityGraphicHolder;
class EntityModule;
class EntityPosition;
class GraphicEntity;

class EntityManager
{
public:
  static EntityManager& Instance();

  size_t createEntityId();

  void processModules(int deltaMs);

  void registerPositionModule(EntityPosition* module);
  EntityPosition* positionModule(size_t entityId);

  void registerGraphicHolderModule(EntityGraphicHolder* module);
  EntityGraphicHolder* GraphicHolderModule(size_t entityId);

private:
  EntityManager();

private:
  size_t _maxEntity;
  std::vector<EntityPosition*> _positionModules;
  std::vector<EntityGraphicHolder*> _graphicHolderModules;
};

namespace EntityManagerHelpers
{
size_t createSimpleUnit(GraphicEntity* graphicEntity);
}

#endif // ENTITYMANAGER_H
