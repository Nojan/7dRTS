#ifndef MEMORYTRACKER_H
#define MEMORYTRACKER_H

#ifndef DEBUG

#include <map>

namespace core {

class MemoryTracker
{
public:
  static MemoryTracker& Instance();

  void* allocate(std::size_t size, int line, const char* filename);
  void deallocate(void* ptr);

  void nextDelete(const char* filename, int line);

private:
  MemoryTracker();
  ~MemoryTracker();

  struct MemoryBlock
  {
    size_t _size;
    size_t _line;
    std::string _filename;

    MemoryBlock()
      : _size(-1)
      , _line(-1)
      , _filename("")
    {}

    MemoryBlock(size_t size, int line, std::string filename)
      : _size(size)
      , _line(line)
      , _filename(filename)
    {}
  };
  std::map< void*, MemoryBlock > _memoryBlockMap;
};

} //namespace core

inline void* operator new(size_t size, size_t line, const char* filename)
{
  return core::MemoryTracker::Instance().allocate(size, line, filename);
}

inline void* operator new[](size_t size, size_t line, const char* filename)
{
  return core::MemoryTracker::Instance().allocate(size, line, filename);
}

inline void operator delete(void* ptr)
{
  core::MemoryTracker::Instance().deallocate(ptr);
}

inline void operator delete[](void* ptr)
{
  core::MemoryTracker::Instance().deallocate(ptr);
}

#ifndef new
    #define new new(__LINE__, __FILE__)
#endif

#endif // DEBUG

#endif // MEMORYTRACKER_H


