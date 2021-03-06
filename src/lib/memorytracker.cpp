#ifdef USE_MEMORYTRACKER

#include "memorytracker.h"

#include <malloc.h>

using namespace core;

MemoryTracker &MemoryTracker::Instance()
{
  static MemoryTracker instance;
  return instance;
}

void *MemoryTracker::allocate(std::size_t size, int line, const char *filename)
{
  void* ptr = malloc( size );

  MemoryBlock memoryBlock(size, line, filename);
  _memoryBlockMap[ptr] = memoryBlock;

  return ptr;
}

void MemoryTracker::deallocate(void *ptr)
{
  auto it = _memoryBlockMap.find(ptr);

  if( it == _memoryBlockMap.end() )
  {
    //wild pointer
    free( ptr );
    return;
  }
  _memoryBlockMap.erase(it);
  if( ptr != NULL )
    free( ptr );
}

MemoryTracker::MemoryTracker()
{
}

MemoryTracker::~MemoryTracker()
{
  std::cout << std::endl << _memoryBlockMap.size() << " memory leak" << std::endl;
  for(auto it = _memoryBlockMap.cbegin(); it != _memoryBlockMap.cend(); ++it)
  {
    const MemoryBlock& mb = it->second;
    std::cout << "leak@" << mb._filename << ":" << mb._line << std::endl;
  }
}

#endif //USE_MEMORYTRACKER
