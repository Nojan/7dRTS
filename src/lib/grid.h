#ifndef GRID_H
#define GRID_H


// include
// std
#include <vector>

namespace core
{

template <typename T>
class Grid
{
public:
  Grid();
  Grid(std::size_t width, std::size_t height);

  std::size_t width() const;
  std::size_t height() const;

  bool inGrid(std::size_t x, std::size_t y) const;

  void resize(std::size_t width, std::size_t height);

  T& operator()(std::size_t x, std::size_t y);
  const T& at(std::size_t x, std::size_t y) const;

private:
  std::size_t _width, _height;
  std::vector<T> _data;
};


// definition


template <typename T>
inline Grid<T>::Grid()
  : _width(0)
  , _height(0)
  , _data(0)
{ }


template <typename T>
inline Grid<T>::Grid(std::size_t width, std::size_t height)
  : _width(width)
  , _height(height)
  , _data(_height*_width)
{ }


template <typename T>
inline std::size_t Grid<T>::width() const
{
  return _width;
}


template <typename T>
inline std::size_t Grid<T>::height() const
{
  return _height;
}


template <typename T>
bool Grid<T>::inGrid(std::size_t x, std::size_t y) const
{
  return x < _width && y < _height;
}


template <typename T>
inline void Grid<T>::resize(std::size_t width, std::size_t height)
{
  _height = height;
  _width = width;
  _data.resize(_height*_width);
}


template <typename T>
inline T& Grid<T>::operator()(std::size_t x, std::size_t y)
{
  return _data[x*_height + y];
}


template <typename T>
inline const T& Grid<T>::at(std::size_t x, std::size_t y) const
{
  return _data[x*_height + y];
}

} // core

#endif // GRID_H
