#pragma once
#include "OpenGL.h"

#include <list>

#include "RefCount.h"

namespace FGF
{
	class SceneNode: public RefCount
	{
	public:
		SceneNode(SceneNode* parent, int pass = 0);
		virtual ~SceneNode(void);
		void addChild(SceneNode* child);
		void removeChild(SceneNode* child);
		void setParent(SceneNode* parent);
		SceneNode* getParent();

		void rotate(float a);
		void translate(float dx, float dy);
		void scale(float sx, float sy);
		void updateChildren(float dt);
		void renderChildren(int curPass);
		virtual void Update(float dt);
		virtual void Render(int curPass);
		void prepare(int curPass);//prepares node for rendering
		void setPass(int newPass);

	protected:
		std::list<SceneNode*> child;
		SceneNode* parent;

		bool render;

		int pass;

		float rot;
		float dx, dy;
		float sx, sy;
	};
}