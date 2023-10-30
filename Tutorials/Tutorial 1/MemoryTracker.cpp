#include "MemoryTracker.h"


void MemoryTracker::AddBytesAllocated(int numberOfBytes)
{
	AllocatedBytes += numberOfBytes;
}

void MemoryTracker::RemoveBytesAllocated(int numberOfBytes)
{
	AllocatedBytes -= numberOfBytes;
}
