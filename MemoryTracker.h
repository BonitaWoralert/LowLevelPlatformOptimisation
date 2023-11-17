#pragma once
#include <iostream>

struct Header
{
	int size; //size of main allocated section
	int checkValue;
	Header* pNext;
	Header* pPrev;
};

struct Footer
{
	int checkValue;
};

static int AllocatedBytes{ 0 };
extern Header* pLast; //stores last header added to list
extern Header* pFirst; //first header in list

class MemoryTracker
{
private:

	MemoryTracker()
	{
	}

public:
	MemoryTracker(const MemoryTracker& obj)
		= delete;

	static void WalkTheHeap();

	inline static void AddBytesAllocated(size_t numberOfBytes) { AllocatedBytes += numberOfBytes; }
	inline static void RemoveBytesAllocated(size_t numberOfBytes) { AllocatedBytes -= numberOfBytes; }
	inline static int GetAllocated() { return AllocatedBytes; }
};