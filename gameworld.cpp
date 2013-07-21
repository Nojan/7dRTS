#include "gameworld.h"

#include "entitymanager.h"
#include "graphicentity.h"

const int framestep = 1000 / 33;

GameWorld::GameWorld(QObject *parent) :
  QObject(parent)
{
  _graphicsScene.setSceneRect(-300, -300, 600, 600);
  _graphicsScene.setItemIndexMethod(QGraphicsScene::NoIndex);

  GraphicEntity * unitGraphic = new GraphicEntity();
  EntityManagerHelpers::createSimpleUnit(unitGraphic);
  _graphicsScene.addItem(unitGraphic);

  QObject::connect(&_gameplayTimer, SIGNAL(timeout()), this, SLOT(runWorld()));
  switchPause();
}

QGraphicsScene *GameWorld::scene()
{
  return &_graphicsScene;
}

void GameWorld::runWorld()
{
  EntityManager::Instance().processModules(framestep);

  _graphicsScene.advance();
}

void GameWorld::switchPause()
{
  if(_gameplayTimer.isActive())
    _gameplayTimer.stop();
  else
    _gameplayTimer.start(framestep);
}
