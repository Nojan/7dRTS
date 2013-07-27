#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "pch.h"

#include <QTimer>

class GameWorld : public QObject
{
  Q_OBJECT
public:
  explicit GameWorld(QObject *parent = 0);

  QGraphicsScene * scene();

signals:
  
public slots:
  void runWorld();
  void switchPause();

private:
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};

#endif // GAMEWORLD_H
