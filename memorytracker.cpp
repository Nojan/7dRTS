#include "memorytracker.h"

#include <iostream>
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
  std::cout << _memoryBlockMap.size() << " memory leak" << std::endl;
  for(auto it = _memoryBlockMap.cbegin(); it != _memoryBlockMap.cend(); ++it)
  {
    const MemoryBlock& mb = it->second;
    std::cout << mb._filename << ":" << mb._line << std::endl;
  }
}
