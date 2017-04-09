#define DEBUG

#include <iostream>
#include "BasicAllocator.h"

#ifdef DEBUG
	#include "Debug.h"
#endif // DEBUG



//https://docs.google.com/spreadsheets/d/1bKVzQDfNYuuWYO_aafpt-IXgwAFAKcd_S7wIcL0Xnro/edit?usp=sharing

int main()
{
	bool continueLoop = true;
	/*do
	{
		Debug::startTimer();
		continueLoop = false;
	} while (continueLoop);
	Debug::endTimer();*/

	TIMER_MICRO(BasicAllocator::Init());

	DEBUG(Debug::Log("Free Memory: " + std::to_string(BasicAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(BasicAllocator::getUsedMem())));
	int data = 52;
	int secondData = 78;
	int* dataPtr;
	TIMER_MICRO(dataPtr = (int*)BasicAllocator::Alloc(&data, sizeof(data)));
	printf("Data Ptr is: %d\n", dataPtr);
	printf("Data is %d\n", *dataPtr);

	int* secondDataPtr;
	TIMER_MICRO(secondDataPtr = (int*)BasicAllocator::Alloc(&secondData, sizeof(secondData)));
	printf("2nd Data Ptr is: %d\n", secondDataPtr);
	printf("2nd Data is %d\n", *secondDataPtr);
	printf("Data Ptr is: %d\n", dataPtr);
	printf("Data is %d\n", *dataPtr);

	//BasicAllocator::Dealloc(dataPtr);

	//int* dataPtr;
	TIMER_MICRO(dataPtr = (int*)BasicAllocator::Alloc(&secondData, sizeof(secondData)));
	printf("2nd Data Ptr is: %d\n", secondDataPtr);
	printf("2nd Data is %d\n", *secondDataPtr);
	printf("Data Ptr is: %d\n", dataPtr);
	printf("Data is %d\n", *dataPtr);

	BasicAllocator::showMem(secondDataPtr);

	DEBUG(Debug::Log("Free Memory: " + std::to_string(BasicAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(BasicAllocator::getUsedMem())));


	TIMER_MICRO(BasicAllocator::Destroy());

	getchar();
	return 0;
}