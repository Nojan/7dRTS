#include "gameview.h"
#include "gameworld.h"

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

  QObject::connect(&view, SIGNAL(switchPause()), &world, SLOT(switchPause()));

  return a.exec();
}
