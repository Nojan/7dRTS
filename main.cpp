#include "constantes.h"
#include "entitymanagerhelper.h"
#include "gameview.h"
#include "gameworld.h"
#include "graphicentity.h"

#include "hardcodedmap.h"
#include "generalmap.h"
#include "graphicmap.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  GameWorld world;

  GameView view(world.scene());
  view.setRenderHint(QPainter::Antialiasing);
  view.setCacheMode(QGraphicsView::CacheBackground);
  view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view.setDragMode(QGraphicsView::ScrollHandDrag);
  view.setWindowTitle("7dRTS");
  view.resize(800, 600);
  view.show();

  // test map
  core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
  graphic::GraphicMap* gMap = new graphic::GraphicMap(&map);
  QImage img(gMap->pixmap().toImage());
  img.save("test.png");

  world.scene()->setSceneRect(0, 0, map.tileGrid().height() * core::tileSize, map.tileGrid().width() * core::tileSize);
  world.scene()->addItem(gMap);

  {
    GraphicEntity * unitGraphic = new GraphicEntity();
    unitGraphic->setBrush(Qt::red);
    const Eigen::Vector2f position(10,5);
    const EntityTeam::Team team(EntityTeam::TeamA);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, position* core::tileSize, team);
    world.scene()->addItem(unitGraphic);
  }

  {
    GraphicEntity * unitGraphic = new GraphicEntity();
    unitGraphic->setBrush(Qt::blue);
    const Eigen::Vector2f position(3,12);
    const EntityTeam::Team team(EntityTeam::TeamB);
    EntityManagerHelpers::createSimpleUnit(unitGraphic, position* core::tileSize, team);
    world.scene()->addItem(unitGraphic);
  }

  QObject::connect(&view, SIGNAL(switchPause()), &world, SLOT(switchPause()));

  return a.exec();
}
