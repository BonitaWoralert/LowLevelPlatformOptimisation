#pragma once
#include "MemoryTracker.h"
class MemAlloc
{
	void* operator new (size_t size, MemoryTracker* pTracker, int test);
	//void* operator new (size_t size);

	//void operator delete (void* pmem, MemoryTracker* pTracker);
	void operator delete (void* pMem);
};

