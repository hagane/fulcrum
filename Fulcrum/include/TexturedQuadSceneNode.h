#pragma once
#include "QuadSceneNode.h"
#include "OpenGL.h"
#include "Vertex3f.h"
#include "Texture.h"
#include <SDL.h>

namespace FGF
{
	class TexturedQuadSceneNode :
		public QuadSceneNode
	{
	public:
		TexturedQuadSceneNode(SceneNode* parent, float x, float y, float w, float h, Texture* aTex);
		virtual ~TexturedQuadSceneNode(void);
		virtual void Render(int curPass);
	protected:
		Texture* tex;
		float* texCoord1;
		float* texCoord2;
	};
}