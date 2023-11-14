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
extern Header* pLast {nullptr}; //stores last header added to list
extern Header* pFirst {nullptr}; //first header in list

class MemoryTracker
{
private:

	MemoryTracker()
	{
	}

public:
	/*static Header* pLast;
	static Header* pFirst;*/

	MemoryTracker(const MemoryTracker& obj)
		= delete;

	inline static void WalkTheHeap()
	{
		Header* current = pFirst;
		std::cout << "\n\n\n" << pLast;
		std::cout << "\n\n\n" << pFirst;

		while (current != pLast) //prob do this in a better way once it works
		{
			std::cout << "Header->prev = " << current->pPrev << "\tHeader->next = " << current->pNext;
			current = current->pNext;
		} //also have to check checkValues.
	}

	inline static void AddBytesAllocated(size_t numberOfBytes) { AllocatedBytes += numberOfBytes; }
	inline static void RemoveBytesAllocated(size_t numberOfBytes) { AllocatedBytes -= numberOfBytes; }
	inline static int GetAllocated() { return AllocatedBytes; }
};

//Header* MemoryTracker::pFirst{nullptr};
//Header* MemoryTracker::pLast{nullptr};