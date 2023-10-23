#pragma once
#include "MemoryTracker.h"
class MemAlloc
{
	void* operator new (size_t size);
	void* operator new (size_t size, MemoryTracker* pTracker);

	void operator delete (void* pMem);
	void operator delete (void* pmem, MemoryTracker* pTracker);
};

