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
		QueryPerformanceCounter(&t_stop);//Ќас интересует
		dt = (t_stop.QuadPart - t_start.QuadPart);//разница между t_start и t_stop
		dt /= freq.QuadPart;//в секундах
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