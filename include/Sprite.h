#pragma once
#include "OpenGL.h"
#include "QuadSceneNode.h"
#include "Texture.h"
#include <vector>
#include "export.h"

namespace FGF
{
	class EXPORT Sprite :
		public QuadSceneNode
	{
	public:
		Sprite(SceneNode* parent, float x, float y, float w, float h, float fps, Texture* aTex);
		virtual ~Sprite(void);
		virtual void Update(float dt);
		virtual void Render(int curPass);
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

		Texture* tex;
		float* texCoord1;
		float* texCoord2;
	};
}
