#pragma once
class MemAlloc
{
	void* operator new (size_t size);
	void operator delete (void* pMem);
};

