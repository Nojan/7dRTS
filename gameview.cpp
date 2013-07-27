#include "gameview.h"

#include <QKeyEvent>

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
