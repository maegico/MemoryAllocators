#include "BasicAllocator.h"

void* BasicAllocator::MemoryBuffer;

void BasicAllocator::Init()
{
	MemoryBuffer = malloc(MAX_BUFFER_SIZE);
}

void BasicAllocator::Destroy()
{
	free(MemoryBuffer);
}

void* BasicAllocator::Alloc(uint32_t size)
{
	//return MemoryBuffer+size;
	return nullptr;	//place holder
}

//BasicAllocator::BasicAllocator()
//{
//	MemoryBuffer = malloc(MAX_BUFFER_SIZE);
//}
//
//
//BasicAllocator::~BasicAllocator()
//{
//	free(MemoryBuffer);
//}
