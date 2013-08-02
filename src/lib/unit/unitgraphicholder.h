#ifndef UNITGRAPHICHOLDER_H
#define UNITGRAPHICHOLDER_H

// include
// core
#include "entitygraphicholder.h"

// forward declaration
namespace graphic
{
class GraphicUnit;
}

namespace core
{

class UnitGraphicHolder : public EntityGraphicHolder
{
public:
  UnitGraphicHolder(std::size_t eId, graphic::GraphicUnit* gu);
};

} // core

#endif // UNITGRAPHICHOLDER_H
