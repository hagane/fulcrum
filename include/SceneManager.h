#pragma once
#include <list>
#include "OpenGL.h"
#include "SceneNode.h"
#include "export.h"

namespace FGF
{
	/** \brief Scene manager.
	 * A class that represents a full scene.
	 */
	class EXPORT SceneManager
	{
	public:
		SceneManager(void);
		virtual ~SceneManager(void);

		/**
		 * That method is called every frame. Override it to
		 * implement scene-wise custom logic.
		 * @param dt Time passed since last frame in seconds.
		 */
		void Update(float dt);

		/**
		 * Renders a scene.
		 */
		void Render();

		/**
		 * Adds a node to root of scene graph.
		 * @param node node to add
		 */
		void addNode(SceneNode* node);

	private:
		SceneNode* root;
	};
}
