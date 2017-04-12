#include <iostream>
#include "TestFixedSizedAllocator.h"
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
	/*Debug::startTimer();
	for (int i = 0; i < 1000; i++)
	{
		Debug::Log("For Loop.");
	}
	Debug::endTimerMilli();

	Debug::Log("Just testing this.");
*/

	for (int i = 0; i < 30; i++)
	{
		printf("Remainder is of %d is %d.\n", i, i % 2);
	}

	getchar();
	return 0;
}