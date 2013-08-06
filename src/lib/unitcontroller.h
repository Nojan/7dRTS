#ifndef UNITCONTROLLER_H
#define UNITCONTROLLER_H

// include
// std
#include <vector>

// Eigen
#include <Eigen/Eigen>

namespace core
{

class UnitController
{
public:
  void selectedUnit(std::vector<std::size_t> su);
  const std::vector<std::size_t>& selectedUnit() const;

  void selectedTarget(const Eigen::Vector2i& target);

private:
  std::vector<std::size_t> _selectedUnit;
};

} // core

#endif // UNITCONTROLLER_H
