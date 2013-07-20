#include "gameview.h"
#include "graphicentity.h"

#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QGraphicsScene scene;
  scene.setSceneRect(-300, -300, 600, 600);
  scene.setItemIndexMethod(QGraphicsScene::NoIndex);

  scene.addItem(new GraphicEntity());

  GameView view(&scene);
  view.setRenderHint(QPainter::Antialiasing);
  view.setCacheMode(QGraphicsView::CacheBackground);
  view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  view.setDragMode(QGraphicsView::ScrollHandDrag);
  view.setWindowTitle("7dRTS");
  view.resize(400, 300);
  view.show();

  return a.exec();
}
