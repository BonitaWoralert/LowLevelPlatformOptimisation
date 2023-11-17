#include "MemoryTracker.h"

Header* pLast { nullptr };
Header* pFirst{ nullptr };

void MemoryTracker::WalkTheHeap()
{
	Header* current = pFirst;

	std::cout << "\n\nWalking the heap:\n";

	while (current!=nullptr)
	{
		std::cout << "Current header: " << current << "\tSize in header: " << current->size << "\tPrev header: " << current->pPrev << "\tNext header: " << current->pNext <<
			"\tCheck value: " << current->checkValue << std::endl;
		current = current->pNext;
	} //also have to check checkValues.
}
