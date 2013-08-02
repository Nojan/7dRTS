#include "constantes.h"
#include "entitymanagerhelper.h"
#include "gameview.h"
#include "gameworld.h"
#include "unit/graphicunit.h"

#include "hardcodedmap.h"
#include "generalmap.h"
#include "graphicmap.h"
#include "soundengine.h"
#include "graphicdoor.h"

#include <QApplication>
#include <QtWidgets>


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  // test map
  core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
  graphic::GraphicMap* gMap = new graphic::GraphicMap(&map);

  QGraphicsScene * scene = GameWorld::Instance().scene();

  scene->setSceneRect(0, 0, map.tileGrid().height() * core::tileSize, map.tileGrid().width() * core::tileSize);
  scene->addItem(gMap);

  const Eigen::Vector2f mapHalfSize(map.tileGrid().height()*0.5f, map.tileGrid().width()*0.5f);
  {
    GraphicUnit * unitGraphic = new GraphicUnit();
    const Eigen::Vector2f position(0,0);
    const EntityTeam::Team teamId(EntityTeam::TeamA);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    GraphicUnit * unitGraphic = new GraphicUnit();
    const Eigen::Vector2f position(2,0);
    const EntityTeam::Team teamId(EntityTeam::TeamA);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    GraphicUnit * unitGraphic = new GraphicUnit();
    const Eigen::Vector2f position(10,10);
    const EntityTeam::Team teamId(EntityTeam::TeamB);
    EntityManagerHelpers::createUnitTank(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  {
    GraphicUnit * unitGraphic = new GraphicUnit();
    const Eigen::Vector2f position(12,10);
    const EntityTeam::Team teamId(EntityTeam::TeamB);
    EntityManagerHelpers::createUnitRapide(unitGraphic, (position+mapHalfSize)* core::tileSize, teamId);
    unitGraphic->setBrush(EntityTeam::brushFromTeamId(teamId));
    scene->addItem(unitGraphic);
  }

  for(const core::Room& r: map.rooms())
  {
    for(const core::Door& d: r.doors)
    {
      double length = d.edges().size()*core::tileSize;
      const core::EdgePos& edge = d.edges().front();
      double angle = edge.from.x == edge.to.x ? 0. : 90.;
      Eigen::Vector2f pos = d.center().cast<float>();
      graphic::GraphicDoor* doorGraphic = new graphic::GraphicDoor(length, angle);
      const EntityTeam::Team teamId(EntityTeam::TeamA);
      EntityManagerHelpers::createUnitDoor(doorGraphic, pos, teamId);
      scene->addItem(doorGraphic);
    }
  }

  GameView view(scene);
  view.setRenderHint(QPainter::Antialiasing);
  view.setCacheMode(QGraphicsView::CacheBackground);
  view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view.setDragMode(QGraphicsView::RubberBandDrag);
  view.setWindowTitle("7dRTS");
  view.resize(800, 600);
  view.show();

  QObject::connect(&view, SIGNAL(switchPause()), &GameWorld::Instance(), SLOT(switchPause()));

  // Chargement des sons
  SoundEngine::Instance().preloadSoundEffect(":/sound/Laser_Shoot.wav");

  return a.exec();
}
