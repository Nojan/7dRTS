#ifndef GIMPIMAGE_H
#define GIMPIMAGE_H

// include
// std
#include <cassert>

// core
#include <grid.h>


namespace core
{

struct GimpColor
{
  unsigned char r, g, b;

  bool operator==(const GimpColor& c) const
  {
    return r == c.r && g == c.g && b == c.b;
  }
};


// defined color
const GimpColor gimpGrass = {0x00, 0x80, 0x00};
const GimpColor gimpFloor = {0x99, 0x99, 0x99};
const GimpColor gimpWall = {0x50, 0x2d, 0x16};


class GimpImage : public Grid<GimpColor>
{
public:
  GimpImage(std::size_t w, std::size_t h, std::size_t bpp, const char* pd)
      : Grid(w, h)
  {
    assert(bpp == 3);

    const unsigned char* iter = (unsigned char*)(pd);
    for(std::size_t x = 0; x < w; ++x)
    {
      for(std::size_t y = 0; y < h; ++y)
      {
        operator()(y, x) = {*(iter+0), *(iter+1), *(iter+2)};
        iter += 3;
      }
    }
  }
};

} // core


#endif // GIMPIMAGE_H
