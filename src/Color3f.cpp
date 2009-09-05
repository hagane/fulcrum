#include "Color3f.h"

namespace FGF
{
	Color3f::Color3f()
	{
		rgb[0] = 1;
		rgb[1] = 1;
		rgb[2] = 1;
	}

	Color3f::Color3f(float r, float g, float b)
	{
		rgb[0] = r;
		rgb[1] = g;
		rgb[2] = b;
	}
	
	Color3f::Color3f(float* rgb)
	{
		this->rgb[0] = rgb[0];
		this->rgb[1] = rgb[1];
		this->rgb[2] = rgb[2];
	}

	Color3f::~Color3f()
	{
	}

	void Color3f::activate()
	{
		glColor3fv(rgb);
	}
}