#pragma once
#define DEBUG

#include <cstdint>
#include <malloc.h>

#ifdef DEBUG
	#include <iostream>
#endif // DEBUG

//About a MB of data
#define MAX_BUFFER_SIZE 1024 * 1024	//in bytes
#define MEM_HEADER_SIZE 2			//in bytes
#define PROBLEM 263152

class SingleDataTypeAllocator
{
public:
	static void Init();
	static void Destroy();

	static void* Alloc(void* data, uint32_t size);
	static void Dealloc(void* position);

	static uint32_t getFreeMem();
	static uint32_t getUsedMem();
	
	static void showMem(void* position);

private:
	static void* MemoryBuffer;

	static uint32_t freeMem;
	static uint32_t usedMem;
};

