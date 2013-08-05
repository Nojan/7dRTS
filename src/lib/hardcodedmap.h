#ifndef HARDCODEDMAP_H
#define HARDCODEDMAP_H

// include
// std
#include <string>
#include <unordered_map>

// core
#include "gimpimage.h"

namespace core
{

struct HardCodedImage
{
  static const std::unordered_map<std::string, const GimpImage*> ImageFromName;

  static const GimpImage test;
};

} // core

#endif // HARDCODEDMAP_H
