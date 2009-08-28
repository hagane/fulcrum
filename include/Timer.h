#pragma once
#include <windows.h>
#include "export.h"

namespace FGF
{
	/** \brief Timer.
	 *
	 * Does chronometrage between two points in time.
	 */
	class EXPORT Timer
	{
	public:
		Timer(void);
		~Timer(void);

		/**
		 * Starts a time count.
		 */
		void start();

		/**
		 * Stops a time count
		 */
		void stop();

		/**
		 * Returns time passed between start() and stop() calls in seconds.
		 */
		float getDelta();

		/**
		 * Returns current FPS.
		 */
		float getFPS();
	private:
		LARGE_INTEGER freq,t_start,t_stop;
		float dt;
	};
}
