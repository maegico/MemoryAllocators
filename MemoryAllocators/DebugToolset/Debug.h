#pragma once
#include <chrono>
#include <iostream>
#include <string>

enum LogType
{
	Info,
	Warning,
	Error
};

class Debug
{
public:
	static void startTimer();
	static void endTimerMicro();
	static void endTimerMilli();

	static void Log(std::string msg, LogType type = Info);

private:
	static std::chrono::high_resolution_clock::time_point time;
};

