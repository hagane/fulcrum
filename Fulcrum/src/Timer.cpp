#include "..\include\Timer.h"
namespace FGF
{
	Timer::Timer(void)
	{
		QueryPerformanceFrequency(&freq);
	}

	Timer::~Timer(void)
	{
	}

	void Timer::start()
	{
		QueryPerformanceCounter(&t_start);
	}

	void Timer::stop()
	{
		QueryPerformanceCounter(&t_stop);
		dt = (t_stop.QuadPart - t_start.QuadPart);
		dt /= freq.QuadPart;
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