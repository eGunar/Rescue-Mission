#pragma once
#include "game.h"


class Timer
{
public:
	Timer(const int duration);
	void Update();



private:
	int duration_;
	int start_time_;
	bool running = false;
	int current_time_;

	void Time();
	void IsDone();

};