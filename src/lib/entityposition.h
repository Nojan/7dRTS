#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"
#include "maptypes.h"

namespace core
{

class EntityPosition : public EntityModule
{
public:
  EntityPosition(std::size_t entityId, const Eigen::Vector2f& position);
  virtual ~EntityPosition() {}

  const Eigen::Vector2f& position() const;
  const TilePos& tilePosition() const;

  void setPosition(const Eigen::Vector2f& position);

  float size() const;

  virtual void update();

protected:
  Eigen::Vector2f _position;
  TilePos _tilePosition;
  float _size;
};

} // core

#endif // ENTITYPOSITION_H
