#pragma once
#include "OpenGL.h"

namespace FGF
{
	class Color3f
	{
	public:
		Color3f(void);
		Color3f(float r, float g, float b);
		Color3f(float* rgb);
		~Color3f(void);
		void activate();

	private:
		float rgb[3];
	};
}
