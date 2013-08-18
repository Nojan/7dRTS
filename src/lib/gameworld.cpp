// associated header
#include "gameworld.h"

// include
// core
#include "constantes.h"
#include "entitymanager.h"
#include "entitymanagerhelper.h"
#include "entitymovement.h"
#include "door/graphicdoor.h"
#include "graphicentity.h"
#include "hardcodedmap.h"
#include "soundengine.h"

// graphic
#include "graphicmap.h"

const int framestep = 1000 / 33;

namespace core
{

GameWorld* GameWorld::_instance = nullptr;


GameWorld::GameWorld()
  : QObject(0)
  , _graphicMap(nullptr)
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
  _ballisticProjectileManager.clear();
  _instance = nullptr;
}


void GameWorld::loadMap(const std::string& mapName)
{
  /// @todo cleanup entities
  _graphicsScene.clear();

  _gMap = GeneralMap::fromGimpImage(*(HardCodedImage::ImageFromName.at(mapName)));
  _pfMap = PathFindingMap(&_gMap);

  _graphicsScene.setSceneRect(0, 0,
                              _gMap.tileGrid().height()*core::tileSize,
                              _gMap.tileGrid().width()*core::tileSize);

  // create the GraphicMap
  // _graphicMap belong to _graphicsScene so we don't need to delete it
  _graphicMap = new graphic::GraphicMap(&_gMap);
  _graphicsScene.addItem(_graphicMap);

  // create all door entity
  for(const core::Room& r: _gMap.rooms())
  {
    for(const core::Door& d: r.doors)
    {
      double length = d.edges().size()*core::tileSize;
      const core::EdgePos& edge = d.edges().front();
      double angle = edge.from.x == edge.to.x ? 0. : 90.;
      Eigen::Vector2f pos = d.center().cast<float>();
      graphic::GraphicDoor* doorGraphic = new graphic::GraphicDoor(length, angle);
      const core::EntityTeam::Team teamId(core::EntityTeam::TeamA);
      EntityManagerHelpers::createUnitDoor(doorGraphic, pos, d.edges(), teamId);
      _graphicsScene.addItem(doorGraphic);
    }
  }
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


EntityMap& GameWorld::entityMap()
{
  return _eMap;
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
