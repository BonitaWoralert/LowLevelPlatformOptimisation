#include "MyObject.h"
#include <iostream>

MyObject::MyObject()
{
	std::cout << "MyObject constructor\n";
}

MyObject::~MyObject()
{
	std::cout << "MyObject destructor\n";
}

//class specific memory allocation
void* MyObject::operator new(size_t size)
{
	std::cout << "Class specific new function\n";
	return ::operator new(size);
}

void MyObject::operator delete(void* p, size_t size)
{
	std::cout << "Class specific delete function\n";
	::operator delete(p);
}