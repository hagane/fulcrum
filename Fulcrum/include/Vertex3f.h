#pragma once
#include "OpenGL.h"

namespace FGF
{
	class Vertex3f
	{
	public:
		Vertex3f(void);
		Vertex3f(float x, float y, float z);
		Vertex3f(float* xyz);
		~Vertex3f(void);

		void render();
		float* coords();
	private:
		float coord[3];
	};
}
