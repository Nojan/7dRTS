#include "gameview.h"
#include "gameworld.h"

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
  view.resize(400, 300);
  view.show();

  // test map
  core::GeneralMap map(core::GeneralMap::fromGimpImage(core::HardCodedImage::test));
  graphic::GraphicMap* gMap = new graphic::GraphicMap(&map);
  QImage img(gMap->pixmap().toImage());
  img.save("test.png");
  world.scene()->addItem(gMap);


  QObject::connect(&view, SIGNAL(switchPause()), &world, SLOT(switchPause()));

  return a.exec();
}
