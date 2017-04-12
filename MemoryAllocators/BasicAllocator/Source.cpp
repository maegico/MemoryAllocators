#define DEBUG

#include <iostream>
#include "SingleDataTypeAllocator.h"
#include "BasicGenericAllocator.h"

#ifdef DEBUG
	#include "Debug.h"
#endif // DEBUG

struct Testing
{
	bool test1;
	bool test2;
	bool test3;
	bool test4;
	bool test5;
	bool test6;
	bool test7;
	bool test8;
};

void SingleDataTypeAllocatorTesting();
void BasicGenericAllocatorTesting();

//https://docs.google.com/spreadsheets/d/1bKVzQDfNYuuWYO_aafpt-IXgwAFAKcd_S7wIcL0Xnro/edit?usp=sharing

int main()
{
	//bool continueLoop = true;
	/*do
	{
		Debug::startTimer();
		continueLoop = false;
	} while (continueLoop);
	Debug::endTimer();*/
	int* data;
	TIMER_MICRO(data = (int*)malloc(sizeof(int)));
	printf("Break\n");
	//SingleDataTypeAllocatorTesting();
	BasicGenericAllocatorTesting();

	getchar();
	return 0;
}

void SingleDataTypeAllocatorTesting()
{
	TIMER_MICRO(SingleDataTypeAllocator::Init());

	DEBUG(Debug::Log("Free Memory: " + std::to_string(SingleDataTypeAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(SingleDataTypeAllocator::getUsedMem())));
	int data = 52;
	int secondData = 78;
	float data3 = 0.5f;

	//int* dataPtr;
	//TIMER_MICRO(dataPtr = (int*)SingleDataTypeAllocator::Alloc(&data, sizeof(data)));
	///*printf("Data Ptr is: %d\n", dataPtr);
	//printf("Data is %d\n", *dataPtr);*/

	//int* secondDataPtr;
	//TIMER_MICRO(secondDataPtr = (int*)SingleDataTypeAllocator::Alloc(&secondData, sizeof(secondData)));
	///*printf("2nd Data Ptr is: %d\n", secondDataPtr);
	//printf("2nd Data is %d\n", *secondDataPtr);
	//printf("Data Ptr is: %d\n", dataPtr);
	//printf("Data is %d\n", *dataPtr);*/

	////SingleDataTypeAllocator::Dealloc(dataPtr);
	//secondData = 9;
	////int* dataPtr;
	//TIMER_MICRO(dataPtr = (int*)SingleDataTypeAllocator::Alloc(&secondData, sizeof(secondData)));
	///*printf("2nd Data Ptr is: %d\n", secondDataPtr);
	//printf("2nd Data is %d\n", *secondDataPtr);
	//printf("Data Ptr is: %d\n", dataPtr);
	//printf("Data is %d\n", *dataPtr);*/

	float* data3Ptr;
	TIMER_NANO(data3Ptr = (float*)SingleDataTypeAllocator::Alloc(&data3, sizeof(data3)));
	printf("Float Ptr is: %d\n", data3Ptr);
	printf("Float is %f\n", *data3Ptr);

	//SingleDataTypeAllocator::showMem(secondDataPtr);

	DEBUG(Debug::Log("Free Memory: " + std::to_string(SingleDataTypeAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(SingleDataTypeAllocator::getUsedMem())));

	//getchar();

	TIMER_MICRO(SingleDataTypeAllocator::Destroy());
}

void BasicGenericAllocatorTesting()
{
	TIMER_MICRO(BasicGenericAllocator::Init());

	DEBUG(Debug::Log("Free Memory: " + std::to_string(BasicGenericAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(BasicGenericAllocator::getUsedMem())));
	int data = 52;
	int secondData = 78;
	float data3 = 0.5f;
	Testing t = { false, true, false, false, false, true, false, false };

	int* dataPtr;
	TIMER_NANO(dataPtr = BasicGenericAllocator::Alloc<int>(secondData));

	float* data3Ptr;
	TIMER_NANO(data3Ptr = BasicGenericAllocator::Alloc<float>(data3));
	
	Testing* tPtr;
	TIMER_NANO(tPtr = BasicGenericAllocator::Alloc<Testing>(t));
	
	printf("Float Ptr is: %d\n", data3Ptr);
	printf("Float is %f\n", *data3Ptr);
	printf("Int Ptr is: %d\n", dataPtr);
	printf("Int is %d\n", *dataPtr);

	printf("BOOL 1: %d\n", tPtr->test1);
	printf("BOOL 2: %d\n", tPtr->test2);
	printf("BOOL 3: %d\n", tPtr->test3);
	printf("BOOL 4: %d\n", tPtr->test4);
	printf("BOOL 5: %d\n", tPtr->test5);
	printf("BOOL 6: %d\n", tPtr->test6);
	printf("BOOL 7: %d\n", tPtr->test7);
	printf("BOOL 8: %d\n", tPtr->test8);

	//BasicGenericAllocator::showMem(nullptr);

	DEBUG(Debug::Log("Free Memory: " + std::to_string(BasicGenericAllocator::getFreeMem())));
	DEBUG(Debug::Log("Used Memory: " + std::to_string(BasicGenericAllocator::getUsedMem())));

	//getchar();

	TIMER_MICRO(BasicGenericAllocator::Destroy());
}