# MemoryAllocators
Creating various memory allocators.

Basic Generic Allocator Features:<br/>
	Allows allocation of any data type<br/>
	Header holding size and whether it is used or not<br/>
	Skipping over used memory<br/>
	Free memory<br/>
	Gives amount of free and used memory<br/>
	
Missing Features:<br/>
	Checking if there is enough space to store the data.<br/>
		Instances to check for:<br/>
			Not enough free memory in the pool<br/>
			Can't save memory due to memory fragmentation<br/>
			A single space that doesn't have enough data<br/>

Possible Changes:<br/>
 	Keep the header the same and use a bit mask to handle the used bit.<br/>
		Would allow use of the full 31 bits of data for size<br/>
