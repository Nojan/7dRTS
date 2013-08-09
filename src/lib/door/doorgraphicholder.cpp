// associated header
#include "doorgraphicholder.h"

// include
// graphic
#include "graphicdoor.h"


namespace core
{

DoorGraphicHolder::DoorGraphicHolder(std::size_t entityId,
                                     graphic::GraphicDoor* doorGraphics,
                                     const Eigen::Vector2f& position)
  : EntityGraphicHolder(entityId, doorGraphics)
  , _doorGraphics(doorGraphics)
  , _openning(false)
{
  _doorGraphics->setPosition(position.x(), position.y());
}


void DoorGraphicHolder::openning(bool op)
{
  _openning = op;
}


void DoorGraphicHolder::update()
{
  if(_openning)
  {
    float open = std::min(_doorGraphics->open() + 0.05f, .8f);
    _doorGraphics->open(open);
  }
  else
  {
    float open = std::max(_doorGraphics->open() - 0.05f, 0.f);
    _doorGraphics->open(open);
  }
}

} // core
