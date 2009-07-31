#pragma once
#include <windows.h>

namespace FGF
{
	class Timer
	{
	public:
		Timer(void);
		~Timer(void);
		void start();
		void stop();
		float getDelta();
		float getFPS();
	private:
		LARGE_INTEGER freq,t_start,t_stop;
		float dt;
	};
}