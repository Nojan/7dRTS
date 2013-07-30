#ifndef GRAPHICPATHFINDINGMAP_H
#define GRAPHICPATHFINDINGMAP_H

// include
// Qt
#include <QGraphicsPixmapItem>


// forward declaration
namespace core
{
class PathFindingMap;
}


namespace graphic
{

class GraphicPathFindingMap : public QGraphicsPixmapItem
{
public:
  GraphicPathFindingMap(const core::PathFindingMap* map, QGraphicsItem* parent=0);

private:
  QPixmap pixmapFromPathFindingMap(const core::PathFindingMap* map);

};

} // graphic

#endif // GRAPHICPATHFINDINGMAP_H
