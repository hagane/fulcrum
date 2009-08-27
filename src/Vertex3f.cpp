#include "..\include\Vertex3f.h"
namespace FGF
{
	Vertex3f::Vertex3f()
	{
		coord[0] = 0;
		coord[1] = 0;
		coord[2] = 0;
	}

	Vertex3f::Vertex3f(float x, float y, float z)
	{
		coord[0] = x;
		coord[1] = y;
		coord[2] = z;
	}

	Vertex3f::Vertex3f(float* xyz)
	{
		coord[0] = xyz[0];
		coord[1] = xyz[1];
		coord[2] = xyz[2];
	}

	Vertex3f::~Vertex3f(void)
	{
	}

	void Vertex3f::render()
	{
		glVertex3fv(coord);
	}

	float* Vertex3f::coords()
	{
		return coord;
	}
}