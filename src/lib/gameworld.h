#ifndef GAMEWORLD_H
#define GAMEWORLD_H

// include
// pch
#include "pch.h"

// core
#include "ballisticprojectilemanager.h"
#include "entitymanager.h"
#include "unitcontroller.h"

class GameWorld : public QObject
{
  Q_OBJECT
public:
  static GameWorld& Instance();

  core::BallisticProjectileManager& ballisticProjectileManager();
  EntityManager& entityManager();
  core::UnitController& unitController();
  QGraphicsScene * scene();

signals:
  
public slots:
  void runWorld();
  void switchPause();

private:
  GameWorld();

private:
  core::BallisticProjectileManager _ballisticProjectileManager;
  EntityManager _entityManager;
  core::UnitController _unitController;
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};

#endif // GAMEWORLD_H
