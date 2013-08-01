// associated header
#include "gameview.h"

// include
// Qt
#include <QKeyEvent>

// core
#include "gameworld.h"
#include "unitcontroller.h"

// graphic
#include "graphicentity.h"


GameView::GameView(QGraphicsScene *scene, QWidget *parent)
  : QGraphicsView(scene, parent)
{
}

void GameView::keyPressEvent(QKeyEvent *event)
{
  if(Qt::Key_Space == event->key())
  {
    emit switchPause();
    event->accept();
  }
  else
    event->ignore();
}


void GameView::mouseReleaseEvent(QMouseEvent* event)
{
  if(event->button() == Qt::LeftButton)
  {
    std::vector<std::size_t> entities;
    for(const QGraphicsItem* item: scene()->selectedItems())
    {
      const GraphicEntity* entity;
      if((entity =
          dynamic_cast<const GraphicEntity*>(item)) != 0)
      {
        entities.push_back(entity->entityId());
      }
    }
    core::UnitController& unitC = GameWorld::Instance().unitController();
    unitC.selectedUnit(entities);

    event->accept();
  }
  else if(event->button() == Qt::RightButton)
  {
    core::UnitController& unitC = GameWorld::Instance().unitController();
    QPointF point(mapToScene(event->pos()));
    Eigen::Vector2i target(point.x(), point.y());
    unitC.selectedTarget(target);

    event->accept();
  }
  QGraphicsView::mouseReleaseEvent(event);
}
