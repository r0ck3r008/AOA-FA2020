#include<stdlib.h>
#include<string.h>

#include"timer.h"

extern FILE *logfile;

using timer::Timer;
using std::cout;
using std::endl;

void Timer :: start()
{
	this->tbeg = high_resolution_clock::now();
}

void Timer :: stop(string &s)
{
	high_resolution_clock::time_point tend = high_resolution_clock::now();
	auto time_span = duration_cast<duration<double>>(tend - this->tbeg);
        fprintf(logfile, "%lf%s", time_span.count(), s.c_str());
}
