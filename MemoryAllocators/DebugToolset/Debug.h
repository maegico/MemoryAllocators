#pragma once
#include <chrono>
#include <iostream>
#include <string>

#define TIMER_NANO(x) {Debug::startTimer(); x; Debug::endTimerNano();}
#define TIMER_MICRO(x) {Debug::startTimer(); x; Debug::endTimerMicro();}
#define TIMER_MILLI(x) {Debug::startTimer(); x; Debug::endTimerMilli();}

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
	static void endTimerNano();
	static void endTimerMicro();
	static void endTimerMilli();

	static void Log(std::string msg, LogType type = Info);

private:
	static std::chrono::high_resolution_clock::time_point time;
};

