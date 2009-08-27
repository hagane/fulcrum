#pragma once
#include "SceneNode.h"
#include "OpenGL.h"
#include "Vertex3f.h"
#include "Color3f.h"
#include "export.h"

namespace FGF
{
	class EXPORT QuadSceneNode :
		public SceneNode
	{
	public:
		QuadSceneNode(SceneNode* parent, float x, float y, float w, float h);
		virtual ~QuadSceneNode(void);
		virtual void Render(int curPass);
		void setOrigin(float ox, float oy);

	protected:
		Vertex3f vertex[4];
		Color3f color[4];
	};
}
