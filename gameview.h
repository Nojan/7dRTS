#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>

class QEvent;

class GameView : public QGraphicsView
{
  Q_OBJECT
public:
  explicit GameView(QGraphicsScene *scene, QWidget *parent = 0);

signals:

public slots:

protected:
  virtual void keyPressEvent(QKeyEvent *event);

protected:
  void switchPause();

private:
  QTimer _gameplayTimer;

};

#endif // GAMEVIEW_H
