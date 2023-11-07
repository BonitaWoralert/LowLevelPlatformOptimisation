#include "MemAlloc.h"
#include <iostream>

MemoryTracker* MemoryTracker::instancePtr = NULL;
MemoryTracker* defaultTracker = MemoryTracker::getInstance();

struct Header
{
	int size; //size of main allocated section
	MemoryTracker* tracker; //memory tracker used
};

struct Footer
{
	int reserved;
};

void* operator new (size_t size)
{
	std::cout << "new is being called\n";

	size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested bytes + size of header + size of footer
	char* pMem = (char*)malloc(nRequestedBytes); //allocate this
	Header* pHeader = (Header*)pMem; //header pointer = start of allocated memory

	pHeader->size = size; //set size int to the same as size passed into new
	pHeader->tracker = defaultTracker;
	pHeader->tracker->AddBytesAllocated(size);
	//std::cout << "Value in header in new = " << pHeader->size << std::endl;
	std::cout << "Current bytes allocated = " << pHeader->tracker->GetAllocated() << std::endl;

	void* pFooterAddr = pMem + sizeof(Header) + size; //pointer to footer (start address + header + requested bytes)
	Footer* pFooter = (Footer*)pFooterAddr; //footer pointer = end

	void* pStartMemBlock = pMem + sizeof(Header); //start memory block = requested memory + header

	return pStartMemBlock;
}

void operator delete (void* pMem)
{
	std::cout << "delete is being called\n";
	Header* pHeader = (Header*)((char*)pMem - sizeof(Header)); //header = sizeof(Header) bytes before start
	Footer* pFooter = (Footer*)((char*)pMem + pHeader->size); //footer

	//std::cout << "Value in header on delete = " << pHeader->size << std::endl;
	pHeader->tracker->RemoveBytesAllocated(pHeader->size);
	std::cout << "Current bytes allocated = " << pHeader->tracker->GetAllocated() << std::endl;
	free(pHeader);
}
