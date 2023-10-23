#pragma once
class MemoryTracker
{
public:
	MemoryTracker();
	~MemoryTracker();
	void AddBytesAllocated(int numberOfBytes);
	void RemoveBytesAllocated(int numberOfBytes);

private:
	int AllocatedBytes;
};

