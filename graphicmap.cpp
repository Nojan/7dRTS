// associated header
#include "graphicmap.h"


namespace graphic
{

GraphicMap::GraphicMap(const core::GeneralMap* map, QGraphicsItem* parent)
  : QGraphicsPixmapItem(pixmapFromGeneralMap(map), parent)
{

}


QPixmap GraphicMap::pixmapFromGeneralMap(const core::GeneralMap* /* map */)
{
  return QPixmap();
}

} // graphic

