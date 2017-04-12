#include "SingleDataTypeAllocator.h"

typedef unsigned char byte;

void* SingleDataTypeAllocator::MemoryBuffer;
uint32_t SingleDataTypeAllocator::freeMem;
uint32_t SingleDataTypeAllocator::usedMem;

void SingleDataTypeAllocator::Init()
{
	MemoryBuffer = malloc(MAX_BUFFER_SIZE);
	memset(MemoryBuffer, 0, MAX_BUFFER_SIZE);
	freeMem = MAX_BUFFER_SIZE;
	usedMem = 0;
}

void SingleDataTypeAllocator::Destroy()
{
	free(MemoryBuffer);
}

void* SingleDataTypeAllocator::Alloc(void* data, uint32_t size)
{
	for (uint64_t i = 0; i < MAX_BUFFER_SIZE;)
	{
		int32_t* ptr = (int32_t*)MemoryBuffer + i;
		if (*ptr == NULL || *ptr > 0)
		{
			int32_t header = -size/1;
			*ptr = header;
			*(ptr + 1) = *(int32_t*)data;	//this only works with an int32_t
												//casts a float to an int, causing truncation
												//saving it into an int will also cause the same problem

			//*((byte*)MemoryBuffer + i) = *(byte*)data;
			usedMem += size + 4;
			freeMem -= size + 4;
			return ptr+1;
		}
		else if(*ptr < 0)
		{
			//uint32_t* place = (uint32_t*)MemoryBuffer + i;
			i -= (*ptr/4)-1;
		}
	}
	return nullptr;	//place holder
}

void SingleDataTypeAllocator::Dealloc(void* position)
{
	int32_t* headerPos = (int32_t*)position - 1;
	*headerPos *= -1;
}

uint32_t SingleDataTypeAllocator::getFreeMem()
{
	return freeMem;
}

uint32_t SingleDataTypeAllocator::getUsedMem()
{
	return usedMem;
}

void SingleDataTypeAllocator::showMem(void* position)
{
	for (int i = 0; i < 4; i++)
	{
		//printf("MemoryBuffer ptrs: 0x%x\n", ((int32_t*)MemoryBuffer + i));
		printf("Here is the mem: %d\n", *((int32_t*)MemoryBuffer + i));
	}
	for (int i = 0; i < 4; i++)
	{
		printf("Here is the mem: %d\n", *((float*)MemoryBuffer + i));
	}
}
