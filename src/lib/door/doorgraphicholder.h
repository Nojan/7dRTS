#ifndef DOORGRAPHICHOLDER_H
#define DOORGRAPHICHOLDER_H

// include
// Eigen
#include <Eigen/Eigen>

// core
#include "entitygraphicholder.h"


// forward declaration
namespace graphic
{
class GraphicDoor;
}


namespace core
{

class DoorGraphicHolder : public EntityGraphicHolder
{
public:
  DoorGraphicHolder(std::size_t entityId,
                    graphic::GraphicDoor* doorGraphics,
                    const Eigen::Vector2f& position);

  void openning(bool op);

  virtual void update();

private:
  graphic::GraphicDoor* _doorGraphics;
  bool _openning;
};

} // core

#endif // DOORGRAPHICHOLDER_H
