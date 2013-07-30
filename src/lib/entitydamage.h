#ifndef ENTITYDAMAGE_H
#define ENTITYDAMAGE_H
#include "pch.h"

#include "entitymodule.h"

class EntityDamage : public EntityModule
{
public:
  EntityDamage(size_t entityId, int healthpoint);

  void applyDamage(const int damagePoint);

  int healthPoint() const;
  int maxHealthPoint() const;

  void update();

private:
  int _healthPoint;
  int _maxHealthPoint;
};

#endif // ENTITYDAMAGE_H
