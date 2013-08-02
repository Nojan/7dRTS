#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// include
// pch
#include "pch.h"

// core
#include "ballisticprojectilemanager.h"
#include "entitymanager.h"
#include "unitcontroller.h"

namespace core
{

class GameWorld : public QObject
{
  Q_OBJECT
public:
  static GameWorld& Instance();

  BallisticProjectileManager& ballisticProjectileManager();
  EntityManager& entityManager();
  UnitController& unitController();
  QGraphicsScene * scene();

signals:
  
public slots:
  void runWorld();
  void switchPause();

private:
  GameWorld();

private:
  BallisticProjectileManager _ballisticProjectileManager;
  EntityManager _entityManager;
  UnitController _unitController;
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};

} // core

#endif // GAMEWORLD_H
