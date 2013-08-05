// associated header
#include "gameworld.h"

// include
// core
#include "entitymanager.h"
#include "entitymanagerhelper.h"
#include "entitymovement.h"
#include "graphicentity.h"
#include "hardcodedmap.h"
#include "soundengine.h"

const int framestep = 1000 / 33;

namespace core
{

GameWorld* GameWorld::_instance = nullptr;


GameWorld::GameWorld()
  :  QObject(0)
{
  // GameWorld should be unique
  // we can also throw instead of assert
  assert(_instance == nullptr);
  _instance = this;

  _graphicsScene.setItemIndexMethod(QGraphicsScene::NoIndex);

  QObject::connect(&_gameplayTimer, SIGNAL(timeout()), this, SLOT(runWorld()));
  switchPause();
}


GameWorld::~GameWorld()
{
  assert(_instance == this);
  _instance = nullptr;
}


void GameWorld::loadMap(const std::string& mapName)
{
  _gMap = GeneralMap::fromGimpImage(*(HardCodedImage::ImageFromName.at(mapName)));
  _pfMap = PathFindingMap(&_gMap);
}


const GeneralMap& GameWorld::generalMap() const
{
  return _gMap;
}


const PathFindingMap& GameWorld::pathFindingMap() const
{
  return _pfMap;
}


GameWorld& GameWorld::Instance()
{
  return *_instance;
}


BallisticProjectileManager &GameWorld::ballisticProjectileManager()
{
  return _ballisticProjectileManager;
}


EntityManager &GameWorld::entityManager()
{
  return _entityManager;
}


UnitController& GameWorld::unitController()
{
  return _unitController;
}


QGraphicsScene *GameWorld::scene()
{
  return &_graphicsScene;
}


void GameWorld::runWorld()
{
  const float fdeltaS = static_cast<float>(framestep)/1000.f;
  _entityManager.processModules(framestep);
  _ballisticProjectileManager.evolve(fdeltaS);

  _graphicsScene.advance();
}

void GameWorld::switchPause()
{
  if(_gameplayTimer.isActive())
    _gameplayTimer.stop();
  else
    _gameplayTimer.start(framestep);
}

} // core
