#pragma once
#include <list>
#include "OpenGL.h"
#include "SceneNode.h"
#include "export.h"

namespace FGF
{
	class EXPORT SceneManager
	{
	public:
		SceneManager(void);
		virtual ~SceneManager(void);
		void Update(float dt);
		void Render();
		void addNode(SceneNode* node);

	private:
		SceneNode* root;
	};
}
