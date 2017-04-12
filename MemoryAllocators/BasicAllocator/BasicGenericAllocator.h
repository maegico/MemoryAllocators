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

/*Basic Overiew of the Memory Allocation Model
 *Memory is stored as two pieces.
 *	The Header and the Data
 *Header:
 *	Stores:
 *		The size of the data allocated
 *		Whether the data is used.
 *	Format:
 *		An int to store the size.
 *		The sign bit tells whether the memory is used or not.
 *Data:
 *	Stores:
 *		The data.
 *	Format:
 *		Stored as the data type 
 *
 *Allocation:
 *	Two Checks:
 *		Null or the Header is Positive:
 *			This means the memory is unused.
 *			Form a header and then save the header and data, back to back.
 *		Header is Negative:
 *			This means the memory is used.
 *			Skip over the size specified in the current header + the size of the header
 *
 *DeAllocation:
 *	Change the header from negative to positive.
*/

class BasicGenericAllocator
{
public:
	//Allocate the memory pool.
	static void Init();
	//Free the memory pool.
	static void Destroy();

	

	// Loop through the memory pool and allocate data in the first free space.
	// @return : A pointer to the data in the memory pool.
	// @param : A reference to the data.
	template<typename T>
	static T* Alloc(T& data)
	{
		//Should I pass by value, so that nothing has to be created first?
		//Also need to handle pointer alignment
		//Also, does this handle array's properly
		//Also, this doesn't check if the first free space is big enough for the data

		for (uint64_t i = 0; i < MAX_BUFFER_SIZE;)
		{
			//The current memory location
			//Casted to an int to handle the header
			int32_t* ptr = (int32_t*)MemoryBuffer + i;
			//The size of the data type being saved
			int32_t size = sizeof(T);
			//check if the space is NULL or the memory location is unused
			if (*ptr == NULL || *ptr > 0)
			{
				//create the header (the format is detailed in the .h)
				int32_t header = -size;
				//save the header in memory
				*ptr = header;
				//move forward pass the header
				//then cast to pointer of the data type passed in and dereference it
				//Reasons:
					//You want to move forward the size of an int32_t
					//you need the cast, so when it is saved the data does not get affected
				*(T*)(ptr + 1) = data;
				//update the amount of used and free data
				usedMem += size + 4;
				freeMem -= size + 4;
				//return the pointer to the data
				return (T*)(ptr + 1);
			}
			else if (*ptr < 0)
			{
				//i -= (*ptr / 4) - 1;
				i -= (*ptr / 4) - 1;
			}
		}
		//if it ever reaches this it means something screwed up
		return nullptr;
	}

	// Deallocates the memory by setting the header's used bit to false.
	// @param : A pointer to the memory to deallocate.
	static void Dealloc(void* position);

	static uint32_t getFreeMem();
	static uint32_t getUsedMem();

	//Ignore the below function,
		//supposed to be a function to loop through the memory
		//It is hard getting this to show exactly what I want
		//just a mishmash of random stuff
	static void showMem(void* position);

private:
	//The memory pool.
	static void* MemoryBuffer;
	//How much free memory is in the pool.
	static uint32_t freeMem;
	//How much memory in the pool is used.
	static uint32_t usedMem;
};

