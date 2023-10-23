#pragma once
class MyObject
{
public:
	//constructor and destructor
	MyObject();
	~MyObject();

	//class specific memory allocation
	static void* operator new(size_t size);
	static void operator delete(void* p, size_t size);
};

