#include "BasicGenericAllocator.h"

void* BasicGenericAllocator::MemoryBuffer;
uint32_t BasicGenericAllocator::freeMem;
uint32_t BasicGenericAllocator::usedMem;

void BasicGenericAllocator::Init()
{
	MemoryBuffer = malloc(MAX_BUFFER_SIZE);
	memset(MemoryBuffer, 0, MAX_BUFFER_SIZE);
	freeMem = MAX_BUFFER_SIZE;
	usedMem = 0;
}

void BasicGenericAllocator::Destroy()
{
	free(MemoryBuffer);
}

void BasicGenericAllocator::Dealloc(void* position)
{
	int32_t* headerPos = (int32_t*)position - 1;
	*headerPos *= -1;
}

uint32_t BasicGenericAllocator::getFreeMem()
{
	return freeMem;
}

uint32_t BasicGenericAllocator::getUsedMem()
{
	return usedMem;
}

void BasicGenericAllocator::showMem(void* position)
{
	int i = 0;
	void* tempPtr = MemoryBuffer;
	for (i; i < 3; i++)
	{
		//printf("MemoryBuffer ptrs: 0x%x\n", ((int32_t*)MemoryBuffer + i));
		printf("Here is the mem: %d\n", *(int32_t*)tempPtr);
		tempPtr = (int32_t*)tempPtr + 1;
	}

	//printf("Here is the mem: %d\n", *((float*)MemoryBuffer + 4));
	printf("Here is the mem: %d\n", *(float*)tempPtr);
}