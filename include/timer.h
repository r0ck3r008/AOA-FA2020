#ifndef TIMER_H
#define TIMER_H

#include<iostream>
#include<chrono>

using std::string;
using namespace std::chrono;

namespace timer {
	class Timer {
		high_resolution_clock::time_point tbeg;
	public:
		void start();
		void stop(string &);
	};
}

#endif
