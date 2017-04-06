#pragma once
#include <cstdint>
#include <malloc.h>

//About a MB of data
#define MAX_BUFFER_SIZE 1024 * 1024	//in bytes
#define MEM_HEADER_SIZE 2			//in bytes

class BasicAllocator
{
public:
	static void Init();
	static void Destroy();

	static void* Alloc(uint32_t size);

	//BasicAllocator();
	//~BasicAllocator();

private:
	static void* MemoryBuffer;
};

