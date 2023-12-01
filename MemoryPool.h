#pragma once
class MemoryPool
{
public:
	MemoryPool(size_t objectSize);
	~MemoryPool();

	void* Alloc(size_t size);
	void Free(void* p, size_t size);
};

