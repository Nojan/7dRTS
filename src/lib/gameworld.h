#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// include
// pch
#include "pch.h"

// core
#include "ballisticprojectilemanager.h"
#include "entitymanager.h"
#include "generalmap.h"
#include "pathfindingmap.h"
#include "unitcontroller.h"

// forward declaration
namespace graphic
{
class GraphicMap;
}


namespace core
{

class GameWorld : public QObject
{
  Q_OBJECT
public:
  static GameWorld& Instance();

public:
  GameWorld();
  ~GameWorld();

  void loadMap(const std::string& mapName);
  const GeneralMap& generalMap() const;
  const PathFindingMap& pathFindingMap() const;

  BallisticProjectileManager& ballisticProjectileManager();
  EntityManager& entityManager();
  UnitController& unitController();
  QGraphicsScene * scene();

signals:

public slots:
  void runWorld();
  void switchPause();

private:
  static GameWorld* _instance;

private:
  BallisticProjectileManager _ballisticProjectileManager;
  EntityManager _entityManager;
  UnitController _unitController;
  GeneralMap _gMap;
  PathFindingMap _pfMap;

  graphic::GraphicMap* _graphicMap;
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};


inline GameWorld& gameworld()
{
  return GameWorld::Instance();
}


} // core

#endif // GAMEWORLD_H
