// associated header
#include "hardcodedmap.h"

// include
// std
#include <cstdint>

namespace core
{

GimpImage HardCodedImage::test = GimpImage{
  64, 64, 3,
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26P-\26P-\26P-\26P-\26P-\26P"
  "-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-"
  "\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-"
  "\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0P-\26"
  "P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0"
  "\0\200\0\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231"
  "P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200"
  "\0\0\200\0\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231"
  "P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231"
  "\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0"
  "\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0"
  "\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231"
  "\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26J4\24P-\26\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231"
  "\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0P-\26"
  "P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231"
  "\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231"
  "\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P"
  "-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
  "q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0",
};

} // core
