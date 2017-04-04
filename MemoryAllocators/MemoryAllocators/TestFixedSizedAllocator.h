#pragma once
#include <malloc.h>

#define MAX_BUFFER_SIZE 1024 * 1024
#define BUFFER_REGION_SIZE 32

class TestFixedSizedAllocator
{
public:
	TestFixedSizedAllocator();
	~TestFixedSizedAllocator();

private:
	void* MemoryBuffer;
};

