#pragma once
#include <list>
#include "OpenGL.h"
#include "SceneNode.h"

namespace FGF
{
	class SceneManager
	{
	public:
		SceneManager(void);
		~SceneManager(void);
		void Update(float dt);
		void Render();
		void addNode(SceneNode* node);

	private:
		SceneNode* root;
	};
}
