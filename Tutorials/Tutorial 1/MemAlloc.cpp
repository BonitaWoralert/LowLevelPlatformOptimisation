#include "MemAlloc.h"
#include <iostream>


struct Header
{
	int size; //size of main allocated section
	MemoryTracker* tracker; //memory tracker used
};

struct Footer
{
	int reserved;
};

void* operator new (size_t size, MemoryTracker* pTracker, int test)
{
	std::cout << "new with tracker is being called\n";

	size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested bytes + size of header + size of footer
	char* pMem = (char*)malloc(nRequestedBytes); //allocate this
	Header* pHeader = (Header*)pMem; //header pointer = start of allocated memory

	pHeader->tracker = pTracker;
	pHeader->size = size; //set size int to the same as size passed into new
	pTracker->AddBytesAllocated(size); // send bytes to memory tracker
	pHeader->tracker->AddBytesAllocated(size);

	std::cout << "Value in header in new = " << pHeader->size << std::endl;
	std::cout << "Bytes allocated = " << pHeader->tracker->GetAllocated() << std::endl;

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

	pHeader->tracker->RemoveBytesAllocated(pHeader->size);
	std::cout << "tracked : " << pHeader->tracker->GetAllocated() << std::endl;

	std::cout << "Value in header on delete = " << pHeader->size << std::endl;
	free(pHeader);
}

/*
void* operator new (size_t size, MemoryTracker* pTracker, int test)
{
	std::cout << "new with tracker is being called\n";

	size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested bytes + size of header + size of footer
	char* pMem = (char*)malloc(nRequestedBytes); //allocate this
	Header* pHeader = (Header*)pMem; //header pointer = start of allocated memory

	pTracker->AddBytesAllocated(size); // send bytes to memory tracker
	pHeader->size = size; //set size int to the same as size passed into new
	pHeader->tracker = pTracker;
	pTracker->AddBytesAllocated(size);

	std::cout << "Value in header in new = " << pHeader->size << std::endl;

	void* pFooterAddr = pMem + sizeof(Header) + size; //pointer to footer (start address + header + requested bytes)
	Footer* pFooter = (Footer*)pFooterAddr; //footer pointer = end

	void* pStartMemBlock = pMem + sizeof(Header); //start memory block = requested memory + header

	return pStartMemBlock;
}

void* operator new (size_t size)
{
	std::cout << "new is being called\n";
	
	size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested bytes + size of header + size of footer
	char* pMem = (char*)malloc(nRequestedBytes); //allocate this
	Header* pHeader = (Header*)pMem; //header pointer = start of allocated memory

	pHeader->size = size; //set size int to the same as size passed into new
	std::cout << "Value in header in new = " << pHeader->size << std::endl;

	void* pFooterAddr = pMem + sizeof(Header) + size; //pointer to footer (start address + header + requested bytes)
	Footer* pFooter = (Footer*)pFooterAddr; //footer pointer = end

	void* pStartMemBlock = pMem + sizeof(Header); //start memory block = requested memory + header
	
	return pStartMemBlock;
}

void operator delete (void* pMem, MemoryTracker* pTracker)
{
	std::cout << "delete with tracker is being called\n";
	Header* pHeader = (Header*)((char*)pMem - sizeof(Header)); //header = sizeof(Header) bytes before start
	Footer* pFooter = (Footer*)((char*)pMem + pHeader->size); //footer

	pTracker = pHeader->tracker;
	pTracker->RemoveBytesAllocated(pHeader->size);
	std::cout << "tracker bytes : " << pTracker->GetAllocated() << std::endl;

	std::cout << "Value in header on delete = " << pHeader->size << std::endl;
	free(pHeader);
}

void operator delete (void* pMem)
{
	std::cout << "delete is being called\n";
	Header* pHeader = (Header*)((char*)pMem - sizeof(Header)); //header = sizeof(Header) bytes before start
	Footer* pFooter = (Footer*)((char*)pMem + pHeader->size); //footer

	std::cout << "Value in header on delete = " << pHeader->size << std::endl;
	free(pHeader);
}

*/