#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "pch.h"

#include "entitymanager.h"

class GameWorld : public QObject
{
  Q_OBJECT
public:
  static GameWorld& Instance();

  EntityManager& entityManager();
  QGraphicsScene * scene();

signals:
  
public slots:
  void runWorld();
  void switchPause();

private:
  GameWorld();

private:
  EntityManager _entityManager;
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};

#endif // GAMEWORLD_H
