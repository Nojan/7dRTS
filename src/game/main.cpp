#include "constantes.h"
#include "entitymanagerhelper.h"
#include "gameview.h"
#include "gameworld.h"
#include "unit/graphicunit.h"

#include "soundengine.h"

#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  core::GameWorld world;

  // load world map
  world.loadMap("test");
  const core::GeneralMap& map = world.generalMap();

  // create some unit
  QGraphicsScene* scene = core::GameWorld::Instance().scene();

  const Eigen::Vector2f mapHalfSize(map.tileGrid().height()*0.5f, map.tileGrid().width()*0.5f);
  {
    graphic::GraphicUnit * unitGraphic = new graphic::GraphicUnit();
    const Eigen::Vector2f position(0,0);
    const core::EntityTeam::Team teamId(core::EntityTeam::TeamA);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(core::EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    graphic::GraphicUnit * unitGraphic = new graphic::GraphicUnit();
    const Eigen::Vector2f position(2,0);
    const core::EntityTeam::Team teamId(core::EntityTeam::TeamA);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(core::EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    graphic::GraphicUnit * unitGraphic = new graphic::GraphicUnit();
    const Eigen::Vector2f position(10,10);
    const core::EntityTeam::Team teamId(core::EntityTeam::TeamB);
    EntityManagerHelpers::createUnitTank(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(core::EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    graphic::GraphicUnit * unitGraphic = new graphic::GraphicUnit();
    const Eigen::Vector2f position(12,10);
    const core::EntityTeam::Team teamId(core::EntityTeam::TeamB);
    EntityManagerHelpers::createUnitRapide(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(core::EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  graphic::GameView view(scene);
  view.setRenderHint(QPainter::Antialiasing);
  view.setCacheMode(QGraphicsView::CacheBackground);
  view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view.setDragMode(QGraphicsView::RubberBandDrag);
  view.setWindowTitle("7dRTS");
  view.resize(800, 600);
  view.show();

  QObject::connect(&view, SIGNAL(switchPause()), &core::GameWorld::Instance(), SLOT(switchPause()));

  // Chargement des sons
  SoundEngine::Instance().preloadSoundEffect(":/sound/Laser_Shoot.wav");

  return a.exec();
}
