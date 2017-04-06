#include <iostream>
#include "BasicAllocator.h"
#include "Debug.h"

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

	Debug::startTimer();
	BasicAllocator::Init();
	Debug::endTimerMicro();

	Debug::startTimer();
	BasicAllocator::Destroy();
	Debug::endTimerMicro();

	getchar();
	return 0;
}