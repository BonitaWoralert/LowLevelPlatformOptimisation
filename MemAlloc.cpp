#include "MemAlloc.h"
#include <iostream>

void* operator new (size_t size)
{
	std::cout << "new is being called\n";
	char* pMem = (char*)malloc(size);
	void* pStartMemBlock = pMem;
	return pStartMemBlock;
}

void operator delete (void* pMem)
{
	std::cout << "delete is being called\n";
	free(pMem);
}
