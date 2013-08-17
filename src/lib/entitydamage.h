#ifndef ENTITYDAMAGE_H
#define ENTITYDAMAGE_H

// include
// pch
#include "pch.h"

// core
#include "entitymodule.h"

namespace core
{

class EntityDamage : public EntityModule
{
public:
  EntityDamage(std::size_t entityId, int healthpoint);

  void applyDamage(const int damagePoint);

  int healthPoint() const;
  int maxHealthPoint() const;

  virtual void update(const int deltaMs) override;

private:
  int _healthPoint;
  int _maxHealthPoint;
};

} // core

#endif // ENTITYDAMAGE_H
