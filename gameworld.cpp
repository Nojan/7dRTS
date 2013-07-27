#include "gameworld.h"

#include "entitymanager.h"
#include "entitymanagerhelper.h"
#include "entitymovement.h"
#include "graphicentity.h"

const int framestep = 1000 / 33;

GameWorld& GameWorld::Instance()
{
    static GameWorld instance;
    return instance;
}

EntityManager &GameWorld::entityManager()
{
  return _entityManager;
}

GameWorld::GameWorld() :
  QObject(0)
{
  _graphicsScene.setItemIndexMethod(QGraphicsScene::NoIndex);

  QObject::connect(&_gameplayTimer, SIGNAL(timeout()), this, SLOT(runWorld()));
  switchPause();
}

QGraphicsScene *GameWorld::scene()
{
  return &_graphicsScene;
}

void GameWorld::runWorld()
{
  _entityManager.processModules(framestep);

  _graphicsScene.advance();
}

void GameWorld::switchPause()
{
  if(_gameplayTimer.isActive())
    _gameplayTimer.stop();
  else
    _gameplayTimer.start(framestep);
}
