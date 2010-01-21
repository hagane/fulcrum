#pragma once
#include "export.h"
#include "OpenGL.h"
#include "SceneNode.h"
#include "Texture.h"

namespace FGF
{
	class EXPORT Background: public SceneNode
	{
	public:
		Background(float aParCoeff, Texture* aTex);
		virtual ~Background();

		virtual void Render();
	
	private:
		float par_coeff;
		Texture* tex;

		float w;
		float h;
	};
}
