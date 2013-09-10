// associated header
#include "hardcodedmap.h"

// include
// std
#include <cstdint>

namespace core
{

const std::unordered_map<std::string, const GimpImage*> HardCodedImage::ImageFromName =
{
  {"test", &HardCodedImage::test}
};


const GimpImage HardCodedImage::test = GimpImage{
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
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\203\203\203\203\203"
  "\203\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0d\0\0d\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0"
  "\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\0\200\0\0d\0""5\36\17\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231"
  "\231\231\231\203\203\203\231\231\231\0\200\0\0\200\0\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0P-\26P-\26P-\26P"
  "-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "P-\26\0\200\0\0\200\0\0\200\0\0d\0\0\200\0\0\200\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231"
  "\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231"
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
  "\231\231\231\231\231\231\231\231\203\203\203\0d\0\0\200\0\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231"
  "\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231"
  "\231\203\203\203\0d\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231"
  "\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0"
  "\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0""5\36\17\0d\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231"
  "\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200"
  "\0\231\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231"
  "\231\231\231\203\203\203\0d\0\0\200\0\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231"
  "\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0d\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\203\203\203\0d\0"
  "\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\0\200\0\231\231\231\203\203\203\231\231\231P-\26\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26P"
  "-\26P-\26P-\26P-\26\"\23\11P-\26P-\26\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0d\0\0\200\0"
  "P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\203\203"
  "\203\203\203\203\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0d\0""5\36\17\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0""5\36\17\0d\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0d\0\0d\0\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231"
  "\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0\231\231"
  "\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0d\0\203\203\203\231\231\231\231\231\231\231\231\231P"
  "-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0d\0\203\203\203\231\231\231\231\231\231\231\231\231P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\203\203\203\0d\0"
  "\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\203\203\203\0"
  "d\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0\200"
  "\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231P-\26\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0P-\26\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\0"
  "\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231\231"
  "\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0\231\231\231"
  "\231\231\231\231\231\231\203\203\203\203\203\203\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231\231\231\231\231\0\200\0\0\200\0P-\26\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0d\0\0d\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0d\0\0\200\0\0\200\0\0\200\0P-\26\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0P-\26\231\231\231"
  "\231\231\231\231\231\231\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\231\231\231\231\231\231\203\203\203\231\231\231\231\231\231\231\231\231"
  "P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0P-\26\231\231\231\231\231\231\203\203\203\0d\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\231\231\231\231\231\231\231\231\231\231"
  "\231\231\231\231\231\231\231\231P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
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
  "\0\0\200\0P-\26P-\26P-\26P-\26P-\26P-\26\"\23\11\"\23\11\"\23\11P-\26P-\26"
  "P-\26P-\26P-\26P-\26P-\26P-\26\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0"
  "\200\0\0\200\0\0\200\0\214O'\214O'\214O'\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
  "\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\310q7\310q7\310q7\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200"
  "\0\0\200\0\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310q7\310"
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
  "q7\310q7\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0"
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
  "\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0\0\200\0",
};

} // core
