//#include "MemoryTracker.h"
//
//void MemoryTracker::WalkTheHeap()
//{
//	Header* current = pFirst;
//	std::cout << "\n\n\n" << pLast;
//	std::cout << "\n\n\n" << pFirst;
//
//	while (current != pLast) //prob do this in a better way once it works
//	{
//		std::cout << "Header->prev = " << current->pPrev << "\tHeader->next = " << current->pNext;
//		current = current->pNext; 
//	} //also have to check checkValues.
//}
