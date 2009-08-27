#pragma once
#include "TexturedQuadSceneNode.h"
#include "Texture.h"
#include <vector>
#include "export.h"

namespace FGF
{
	class EXPORT Sprite :
		public TexturedQuadSceneNode
	{
	public:
		Sprite(SceneNode* parent, float x, float y, float w, float h, float fps, Texture* aTex);
		virtual ~Sprite(void);
		virtual void Update(float dt);
		void setAnimationSequence(int aStart, int aEnd);
		void setFrame(int next);
		
	protected:
		int start;
		int end;
		int frame;
		int frames;

		float tcW;
		float tcH;

		int framesX;
		int framesY;

		float TTL;
		float FPS;
	};
}
