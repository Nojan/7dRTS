#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"

namespace core
{

class EntityPosition : public EntityModule
{
public:
  EntityPosition(std::size_t entityId, const Eigen::Vector2f& position);

  Eigen::Vector2f position() const;
  void setPosition(const Eigen::Vector2f& position);

  float size() const;

  void update();

private:
  Eigen::Vector2f _position;
  float _size;
};

} // core

#endif // ENTITYPOSITION_H
