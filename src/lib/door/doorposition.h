#ifndef DOORPOSITION_H
#define DOORPOSITION_H

// include
// std
#include <vector>

// core
#include "entityposition.h"

namespace core
{

class DoorPosition : public EntityPosition
{
public:
  DoorPosition(std::size_t entityId, const Eigen::Vector2f& centerPos,
               std::vector<EdgePos> edges);

  void update();

private:
  std::vector<EdgePos> _edges;
};

} // core

#endif // DOORPOSITION_H
