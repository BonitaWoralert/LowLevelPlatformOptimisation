#include "MemAlloc.h"
#include "HeaderFooter.h"
#include <iostream>

MemoryTracker* MemoryTracker::instancePtr = NULL;
MemoryTracker* defaultTracker = MemoryTracker::getInstance();

struct Header
{
	int size; //size of main allocated section
	int checkValue;
	MemoryTracker* tracker; //memory tracker used
	Header* pNext;
	Header* pPrev;
};

struct Footer
{
	int checkValue;
};

static Header* pLast {nullptr}; //stores last header added to list
static Header* pFirst {nullptr}; //first header in list

void* operator new (size_t size)
{
	std::cout << "\n\nNew called";

	size_t nRequestedBytes = size + sizeof(Header) + sizeof(Footer); //requested bytes + size of header + size of footer
	char* pMem = (char*)malloc(nRequestedBytes); //allocate this
	Header* pHeader = (Header*)pMem; //header pointer = start of allocated memory

	pHeader->size = size; //set size int to the same as size passed into new
	pHeader->tracker = defaultTracker; //set memory tracker
	pHeader->tracker->AddBytesAllocated(size); //add bytes to memory tracker
	
	if (pLast != nullptr) 
	{
		pHeader->pPrev = pLast; //this header's previous header is pLast
		pLast->pNext = pHeader; //previous header's next header is this one
		pLast = pHeader; //now, this header is the last in the list.
	}
	else
	{
		//this header is the first and last in the list
		pLast = pHeader;
		pFirst = pHeader;
	}

	std::cout << "\nBytes requested: " << size << "\t\tTotal Allocated Bytes = " << pHeader->tracker->GetAllocated();
	void* pFooterAddr = pMem + sizeof(Header) + size; //pointer to footer (start address + header + requested bytes)
	Footer* pFooter = (Footer*)pFooterAddr; //footer pointer = end

	pHeader->checkValue = 0x4EADC0DE; //set header check value
	pFooter->checkValue = 0xF007C0DE; //set footer check value

	std::cout << "\nHeader address: " << &pHeader << "\tFooter Address: " << &pFooter;

	void* pStartMemBlock = pMem + sizeof(Header); //start memory block = requested memory + header

	return pStartMemBlock;
}

void operator delete (void* pMem)
{
	std::cout << "\n\nDelete called";
	Header* pHeader = (Header*)((char*)pMem - sizeof(Header)); //header = sizeof(Header) bytes before start
	Footer* pFooter = (Footer*)((char*)pMem + pHeader->size); //footer

	pHeader->pPrev->pNext = pHeader->pNext; //previous header's pNext is now current header's next
	pHeader->pNext->pPrev = pHeader->pPrev; //next header's pPrev is now current header's prev

	//checkvalues 
	if (pHeader->checkValue == 0x4EADC0DE && pFooter->checkValue == 0xF007C0DE)
	{
		pHeader->tracker->RemoveBytesAllocated(pHeader->size);
		std::cout << "\nBytes deleted: " << pHeader->size << "\t\tTotal Allocated Bytes = " << pHeader->tracker->GetAllocated();
		free(pHeader);
	}
	else //checkvalues incorrect
	{
		if (pHeader->checkValue != 0x4EADC0DE && pFooter->checkValue != 0xF007C0DE)
			std::cout << "\n\nCheck values incorrect in header and footer.\n\n";
		else if (pHeader->checkValue != 0x4EADC0DE)
			std::cout << "\n\nCheck values incorrect in header.\n\n";
		else
			std::cout << "\n\nCheck values incorrect in footer.\n\n";
	}
}
