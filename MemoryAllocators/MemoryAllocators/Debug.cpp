#include "Debug.h"

std::chrono::high_resolution_clock::time_point Debug::time;

Debug::Debug()
{
}

Debug::~Debug()
{
}

void Debug::startTimer()
{
	time = std::chrono::high_resolution_clock::now();
}

void Debug::endTimer()
{
	auto originalTime = time;
	time = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time - originalTime).count();

	printf("Total Time Required: %lld microseconds.\n", duration);
}

void Debug::Log(std::string msg, LogType type)
{
	switch (type)
	{
	case Warning:
		printf("WARNING: %s\n", msg.c_str());
		break;
	case Error:
		printf("ERROR: %s\n", msg.c_str());
		break;
	default:
		printf("INFO: %s\n", msg.c_str());
		break;
	}
}
