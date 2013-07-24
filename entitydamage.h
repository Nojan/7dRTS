#ifndef ENTITYDAMAGE_H
#define ENTITYDAMAGE_H
#include "pch.h"

#include "entitymodule.h"

class EntityDamage : public EntityModule
{
public:
  EntityDamage(size_t entityId);

  void applyDamage(const int damagePoint);

  int healthPoint() const;

  void update();

private:
  int _healthPoint;
};

#endif // ENTITYDAMAGE_H
