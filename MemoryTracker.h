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

static Header* pLast {}; //stores last header added to list
static Header* pFirst {}; //first header in list

static int AllocatedBytes{ 0 };

class MemoryTracker
{
private:
	static MemoryTracker*
		instancePtr;

	MemoryTracker()
	{
	}

public:
	MemoryTracker(const MemoryTracker& obj)
		= delete;

	static MemoryTracker* getInstance()
	{
		if (instancePtr == nullptr)
		{
			instancePtr = new MemoryTracker();
		}
		return instancePtr;
	}
	
	static void WalkTheHeap();

	static void AddBytesAllocated(size_t numberOfBytes) { AllocatedBytes += numberOfBytes; }
	static void RemoveBytesAllocated(size_t numberOfBytes) { AllocatedBytes -= numberOfBytes; }
	int GetAllocated() { return AllocatedBytes; }
};

