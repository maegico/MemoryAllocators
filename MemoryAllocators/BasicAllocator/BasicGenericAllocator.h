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

class BasicGenericAllocator
{
public:
	static void Init();
	static void Destroy();

	//should make this take in a reference
		//that way we know it won't be NULL or empty
		//also, this way it is easier on the user
	//Should I pass by value, so that nothing has to be created first?
	template<typename T>
	static T* Alloc(T& data)
	{
		for (uint64_t i = 0; i < MAX_BUFFER_SIZE;)
		{
			int32_t* ptr = (int32_t*)MemoryBuffer + i;
			int32_t size = sizeof(T);
			if (*ptr == NULL || *ptr > 0)
			{
				int32_t header = -size / 1;
				*ptr = header;
				*((T*)ptr + 1) = data;	//this only works with an int32_t
											//casts a float to an int, causing truncation
											//saving it into an int will also cause the same problem

											//*((byte*)MemoryBuffer + i) = *(byte*)data;
				usedMem += size + 4;
				freeMem -= size + 4;
				return (T*)(ptr + 1);
			}
			else if (*ptr < 0)
			{
				//uint32_t* place = (uint32_t*)MemoryBuffer + i;
				i -= (*ptr / 4) - 1;
			}
		}
		//if it ever reaches this it means something screwed up
		return nullptr;
	}

	static void Dealloc(void* position);

	static uint32_t getFreeMem();
	static uint32_t getUsedMem();

	static void showMem(void* position);

private:
	static void* MemoryBuffer;

	static uint32_t freeMem;
	static uint32_t usedMem;
};

