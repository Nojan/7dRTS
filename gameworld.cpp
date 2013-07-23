#include "gameworld.h"

#include "entitymanager.h"
#include "entitymanagerhelper.h"
#include "entitymovement.h"
#include "graphicentity.h"

const int framestep = 1000 / 33;

GameWorld::GameWorld(QObject *parent) :
  QObject(parent)
{
  _graphicsScene.setSceneRect(-300, -300, 600, 600);
  _graphicsScene.setItemIndexMethod(QGraphicsScene::NoIndex);

  {
    GraphicEntity * unitGraphic = new GraphicEntity();
    unitGraphic->setBrush(Qt::red);
    const Eigen::Vector2f position(0,15);
    const EntityTeam::Team team(EntityTeam::TeamA);
    const size_t entityId =
        EntityManagerHelpers::createSimpleUnit(unitGraphic, position, team);
    EntityMovement * movementModule = EntityManager::Instance().movementModule(entityId);
    MovememtTarget * target = new MovememtTarget(Eigen::Vector2f(30,-15));
    movementModule->SetTarget(target);
    _graphicsScene.addItem(unitGraphic);
  }

  {
    GraphicEntity * unitGraphic = new GraphicEntity();
    unitGraphic->setBrush(Qt::blue);
    const Eigen::Vector2f position(30,-15);
    const EntityTeam::Team team(EntityTeam::TeamB);
    const size_t entityId =
        EntityManagerHelpers::createSimpleUnit(unitGraphic, position, team);
    EntityMovement * movementModule = EntityManager::Instance().movementModule(entityId);
    MovememtTarget * target = new MovememtTarget(Eigen::Vector2f(0,15));
    movementModule->SetTarget(target);
    _graphicsScene.addItem(unitGraphic);
  }

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
