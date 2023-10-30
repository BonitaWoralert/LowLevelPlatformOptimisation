#pragma once
static int AllocatedBytes;
class MemoryTracker
{
public:
	static void AddBytesAllocated(int numberOfBytes);
	static void RemoveBytesAllocated(int numberOfBytes);
	static int GetAllocated() { return AllocatedBytes; }
private:
};

