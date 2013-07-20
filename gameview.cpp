#include "gameview.h"

#include <QKeyEvent>

GameView::GameView(QGraphicsScene *scene, QWidget *parent)
  : QGraphicsView(scene, parent)
{
  QObject::connect(&_gameplayTimer, SIGNAL(timeout()), scene, SLOT(advance()));
  switchPause();
}

void GameView::keyPressEvent(QKeyEvent *event)
{
  if(Qt::Key_Space == event->key())
  {
    switchPause();
    event->accept();
  }
  else
    QGraphicsView::event(event);
}

void GameView::switchPause()
{
  if(_gameplayTimer.isActive())
    _gameplayTimer.stop();
  else
  {
    _gameplayTimer.setInterval(1000 / 33);
    _gameplayTimer.start();
  }
}
