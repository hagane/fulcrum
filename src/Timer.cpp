#include "Timer.h"
namespace FGF
{
	Timer::Timer(void)
	{
		struct timespec ts;
		clock_getres(CLOCK_REALTIME, &ts);
		freq = ts.tv_nsec * 1000000000; //clocks per second
	}

	Timer::~Timer(void)
	{
	}

	void Timer::start()
	{
		struct timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		t_start = ts.tv_sec * 1000000000 + ts.tv_nsec;
	}

	void Timer::stop()
	{
		struct timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		t_stop = ts.tv_sec * 1000000000 + ts.tv_nsec;
		dt = (t_stop - t_start);//разница между t_start и t_stop
		dt /= freq;//в секундах
	}

	float Timer::getDelta()
	{
		return dt;
	}

	float Timer::getFPS()
	{
		return 1.0f/dt;
	}
}
