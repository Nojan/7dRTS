#ifndef GAMEVIEW_H
#define GAMEVIEW_H

// include
// pch
#include "pch.h"

// Qt
#include <QGraphicsView>

// forward declaration
class QEvent;

namespace graphic
{

class GameView : public QGraphicsView
{
  Q_OBJECT
public:
  explicit GameView(QGraphicsScene *scene, QWidget *parent = 0);

signals:
  void switchPause();

public slots:

protected:
  virtual void keyPressEvent(QKeyEvent *event);
  virtual void mouseReleaseEvent(QMouseEvent* event);

private:
};

} // graphic

#endif // GAMEVIEW_H
