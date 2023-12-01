#include "MemoryPool.h"

MemoryPool::MemoryPool(size_t objectSize)
{
	//allocate large memory block
	//each slice >= size an object will need
}

MemoryPool::~MemoryPool()
{
}

void* MemoryPool::Alloc(size_t size)
{
	return nullptr;
}

void MemoryPool::Free(void* p, size_t size)
{
}
