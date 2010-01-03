#pragma once
#include "OpenGL.h"
#include <list>
#include "RefCount.h"
#include "export.h"

namespace FGF
{
	/** \brief Base class for any object.
	 *
	 *	If you need really custom logic and/or render, you should inherit
	 *	from this and override Render and/or Update. When overriding, do
	 *	not forget to call updateChildren and renderChildren respectively.
	 *	
	 *	Render passes are not implemented yet.
	 */
	class EXPORT SceneNode: public RefCount
	{
	public:
		/**
		 * Constructor
		 * @param parent new node's parent node
		 * @param pass -- render pass (not implemented yet)
		 */
		SceneNode(SceneNode* parent);
		virtual ~SceneNode(void);

		/**
		 * Adds a child to this node.
		 * @param child node to be added as child
		 */
		void addChild(SceneNode* child);

		/**
		 * Removes a child removed this node.
		 * @param child node to be removed
		 */
		void removeChild(SceneNode* child);

		/**
		 * Sets the parent of this node.
		 * @param parent new parent.
		 */
		void setParent(SceneNode* parent);

		/**
		 * Returns a parent of this node.
		 */
		SceneNode* getParent();

		/**
		 * Rotates a node counter-clockwise.
		 * @param a -- angle in radians.
		 */
		void rotate(float a);

		/**
		 * Translates a node.
		 * @param dx,dy distance in pixels in X and Y axis respectively
		 */
		void translate(float dx, float dy);

		/**
		 * Scales a node.
		 * @param sx,sy times to scale in X and Y axis respectively
		 */
		void scale(float sx, float sy);

		/**
		 * Calls Update on this node's children.
		 * @param dt time passed since the last frame in seconds
		 */
		void updateChildren(float dt);

		/**
		 * Calls Render on this node's children.
		 */
		void renderChildren();

		/**
		 * If you need custom logic, you should override this method.
		 * @param dt time passed since the last frame in seconds
		 */
		virtual void Update(float dt);

		/**
		 * If you need custom logic, you should override this method.
		 */
		virtual void Render();

		/**
		 * Prepares node for rendering.
		 */
		void prepare();

		/**
		 * Returns node's X-coordinate in a global frame.
		 */
		float getGlobalCoord_X();

		/**
		 * Returns node's Y-coordinate in a global frame.
		 */
		float getGlobalCoord_Y();

	protected:
		/**
		 * List of this node's children.
		 */
		std::list<SceneNode*> child;

		/**
		 * This node's parent.
		 */
		SceneNode* parent;

		/**
		 * Rotation of the node.
		 */
		float rot;

		/**
		 * Coords of the node.
		 */
		float dx, dy;

		/**
		 * Scale of the node.
		 */
		float sx, sy;
	};
}
