// associated header
#include "unitgraphicholder.h"

// include
// graphic
#include "unit/graphicunit.h"

namespace core
{

UnitGraphicHolder::UnitGraphicHolder(std::size_t eId,
                                     graphic::GraphicUnit* gu)
  : EntityGraphicHolder(eId, gu)
{ }

} // core
