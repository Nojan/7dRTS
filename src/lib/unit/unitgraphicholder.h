#ifndef UNITGRAPHICHOLDER_H
#define UNITGRAPHICHOLDER_H

// include
// core
#include "entitygraphicholder.h"

// forward declaration
class GraphicUnit;

class UnitGraphicHolder : public EntityGraphicHolder
{
public:
  UnitGraphicHolder(std::size_t eId, GraphicUnit* gu);
};

#endif // UNITGRAPHICHOLDER_H
