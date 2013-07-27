#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "pch.h"

class GameWorld : public QObject
{
  Q_OBJECT
public:
  static GameWorld& Instance();

  QGraphicsScene * scene();

signals:
  
public slots:
  void runWorld();
  void switchPause();

private:
  GameWorld();

private:
  QGraphicsScene _graphicsScene;
  QTimer _gameplayTimer;
};

#endif // GAMEWORLD_H
