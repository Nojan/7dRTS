#ifndef ENTITYPOSITION_H
#define ENTITYPOSITION_H

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

  int2 position();
  void setPosition(const int2 position);

private:
  int2 _position;
};

#endif // ENTITYPOSITION_H
