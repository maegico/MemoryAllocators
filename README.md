# MemoryAllocators
Creating various memory allocators.

Basic Generic Allocator Features:
	Allows allocation of any data type
	Header holding size and whether it is used or not
	Skipping over used memory
	Free memory
	Gives amount of free and used memory
	
Missing Features:
	Checking if there is enough space to store the data.
		Instances to check for:
			Not enough free memory in the pool
			Can't save memory due to memory fragmentation
			A single space that doesn't have enough data

Possible Changes:
 Keep the header the same and use a bit mask to handle the used bit.
	Would allow use of the full 31 bits of data for size