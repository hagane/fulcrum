#include "..\include\SceneManager.h"

namespace FGF
{
	SceneManager::SceneManager(void)
	{
		root = new SceneNode(NULL);
	}

	SceneManager::~SceneManager(void)
	{
	}

	void SceneManager::Update(float dt)
	{
		root->Update(dt);
	}

	void SceneManager::Render()
	{
		root->Render(0);
	}

	void SceneManager::addNode(SceneNode* node)
	{
		root->addChild(node);
	}
}