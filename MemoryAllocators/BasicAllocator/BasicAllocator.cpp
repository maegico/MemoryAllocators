#include "BasicAllocator.h"

typedef unsigned char byte;

void* BasicAllocator::MemoryBuffer;
uint32_t BasicAllocator::freeMem;
uint32_t BasicAllocator::usedMem;

void BasicAllocator::Init()
{
	MemoryBuffer = malloc(MAX_BUFFER_SIZE);
	memset(MemoryBuffer, 0, MAX_BUFFER_SIZE);
	freeMem = MAX_BUFFER_SIZE;
	usedMem = 0;
}

void BasicAllocator::Destroy()
{
	free(MemoryBuffer);
}

void* BasicAllocator::Alloc(void* data, uint32_t size)
{

	for (uint64_t i = 0; i < MAX_BUFFER_SIZE; i++)
	{
		if (*((byte*)MemoryBuffer + i) == NULL || *((int32_t*)MemoryBuffer + i) > 0)
		{
			byte* mem = ((byte*)MemoryBuffer + i);
			int32_t header = -size;
			*((int32_t*)MemoryBuffer + i) = header;
			*(mem + 4) = *(byte*)data;

			//*((byte*)MemoryBuffer + i) = *(byte*)data;
			usedMem += size + 4;
			freeMem -= size + 4;
			return mem+4;
		}
		else if(*((int32_t*)MemoryBuffer + i) < 0)
		{
			//uint32_t* place = (uint32_t*)MemoryBuffer + i;
			i -= *((int32_t*)MemoryBuffer + i);
		}
	}
	return nullptr;	//place holder
}

void BasicAllocator::Dealloc(void* position)
{
	int32_t* headerPos = (int32_t*)position - 4;
	*headerPos *= -1;
}

uint32_t BasicAllocator::getFreeMem()
{
	return freeMem;
}

uint32_t BasicAllocator::getUsedMem()
{
	return usedMem;
}

void BasicAllocator::showMem(void* position)
{
	for (int i = 0; i < 32; i++)
	{
		printf("MemoryBuffer ptrs: 0x%x\n", ((int32_t*)MemoryBuffer + i));
		//printf("Here is the mem: %d\n", *((int32_t*)MemoryBuffer + i));
	}
}
