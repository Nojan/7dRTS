#ifndef GRAPHICMAP_H
#define GRAPHICMAP_H

// include
// Qt
#include <QGraphicsPixmapItem>


// forward declaration
namespace core
{
class GeneralMap;
}


namespace graphic
{

class GraphicMap : public QGraphicsPixmapItem
{
public:
  GraphicMap(const core::GeneralMap* map, QGraphicsItem* parent=0);

private:
  QPixmap pixmapFromGeneralMap(const core::GeneralMap* map);

private:

};

} // graphic

#endif // GRAPHICMAP_H
