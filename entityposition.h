#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H
#include "pch.h"

#include "entitymodule.h"

class EntityPosition : public EntityModule
{
public:
  EntityPosition(size_t entityId, const Eigen::Vector2f position);

  Eigen::Vector2f position() const;
  void setPosition(const Eigen::Vector2f position);

  float size() const;

  void update();

private:
  Eigen::Vector2f _position;
  float _size;
};

#endif // ENTITYPOSITION_H
