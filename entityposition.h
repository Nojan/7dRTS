#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H
#include "pch.h"

#include "entitymodule.h"

class int2
{
public:
  int2()
    : _x(0)
    , _y(0)
  {
  }

  int2(int x, int y)
    : _x(x)
    , _y(y)
  {
  }

  int x() const { return _x; }
  int y() const { return _y; }

  int2 operator+(const int2& ref)
  {
    return int2(x()+ ref.x(), y() + ref.y());
  }

private:
  int _x;
  int _y;
};

class EntityPosition : public EntityModule
{
public:
  EntityPosition(size_t entityId);

  Eigen::Vector2f position();
  void setPosition(const Eigen::Vector2f position);

  void update();

private:
  Eigen::Vector2f _position;
};

#endif // ENTITYPOSITION_H
